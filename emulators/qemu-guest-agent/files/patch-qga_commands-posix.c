--- qga/commands-posix.c.orig	2020-09-15 16:31:14 UTC
+++ qga/commands-posix.c
@@ -28,6 +28,21 @@
 #include "qemu/cutils.h"
 #include "commands-common.h"
 
+#ifdef BSD_GUEST_AGENT
+#include <ifaddrs.h>
+#include <arpa/inet.h>
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <net/if.h>
+#include <sys/socket.h>
+#include <ifaddrs.h>
+#include <sys/statvfs.h>
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#include <net/ethernet.h>
+#include <net/if_var.h>
+#endif
+
 #ifdef HAVE_UTMPX
 #include <utmpx.h>
 #endif
@@ -85,14 +100,25 @@ void qmp_guest_shutdown(bool has_mode, const char *mod
 {
     const char *shutdown_flag;
     Error *local_err = NULL;
+#ifdef BSD_GUEST_AGENT
+    char *shutdown_mode;
+#endif // BSD_GUEST_AGENT
     pid_t pid;
     int status;
 
     slog("guest-shutdown called, mode: %s", mode);
     if (!has_mode || strcmp(mode, "powerdown") == 0) {
+#ifdef BSD_GUEST_AGENT
+        shutdown_flag = "-p";
+#else
         shutdown_flag = "-P";
+#endif // BSD_GUEST_AGENT
     } else if (strcmp(mode, "halt") == 0) {
+#ifdef BSD_GUEST_AGENT
+        shutdown_flag = "-h";
+#else
         shutdown_flag = "-H";
+#endif // BSD_GUEST_AGENT
     } else if (strcmp(mode, "reboot") == 0) {
         shutdown_flag = "-r";
     } else {
@@ -108,9 +134,15 @@ void qmp_guest_shutdown(bool has_mode, const char *mod
         reopen_fd_to_null(0);
         reopen_fd_to_null(1);
         reopen_fd_to_null(2);
+#ifdef BSD_GUEST_AGENT
+        shutdown_mode = g_strdup_printf("hypervisor initiated %s", mode);
 
+        execle("/sbin/shutdown", "-h", shutdown_flag, "+0",
+               shutdown_mode, (char*)NULL, environ);
+#else
         execle("/sbin/shutdown", "shutdown", "-h", shutdown_flag, "+0",
                "hypervisor initiated shutdown", (char*)NULL, environ);
+#endif // BSD_GUEST_AGENT
         _exit(EXIT_FAILURE);
     } else if (pid < 0) {
         error_setg_errno(errp, errno, "failed to create child process");
@@ -153,9 +185,11 @@ int64_t qmp_guest_get_time(Error **errp)
 void qmp_guest_set_time(bool has_time, int64_t time_ns, Error **errp)
 {
     int ret;
+#ifndef BSD_GUEST_AGENT
     int status;
     pid_t pid;
     Error *local_err = NULL;
+#endif
     struct timeval tv;
     static const char hwclock_path[] = "/sbin/hwclock";
     static int hwclock_available = -1;
@@ -193,7 +227,7 @@ void qmp_guest_set_time(bool has_time, int64_t time_ns
             return;
         }
     }
-
+#ifndef BSD_GUEST_AGENT
     /* Now, if user has passed a time to set and the system time is set, we
      * just need to synchronize the hardware clock. However, if no time was
      * passed, user is requesting the opposite: set the system time from the
@@ -230,6 +264,7 @@ void qmp_guest_set_time(bool has_time, int64_t time_ns
         error_setg(errp, "hwclock failed to set hardware clock to system time");
         return;
     }
+#endif // BSD_GUEST_AGENT
 }
 
 typedef enum {
@@ -2625,25 +2660,263 @@ void qmp_guest_suspend_hybrid(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
 }
-
+#ifndef BSD_GUEST_AGENT
 GuestNetworkInterfaceList *qmp_guest_network_get_interfaces(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
     return NULL;
 }
+#else
+static GuestNetworkInterfaceList *
+guest_find_interface(GuestNetworkInterfaceList *head,
+                     const char *name)
+{
+    for (; head; head = head->next) {
+        if (strcmp(head->value->name, name) == 0) {
+            break;
+        }
+    }
 
+    return head;
+}
+
+static int guest_get_network_stats(const char *name,
+                       GuestNetworkInterfaceStat *stats)
+{
+	return -1;
+}
+
+GuestNetworkInterfaceList *qmp_guest_network_get_interfaces(Error **errp)
+{
+    GuestNetworkInterfaceList *head = NULL, *cur_item = NULL;
+    struct ifaddrs *ifap, *ifa;
+
+    if (getifaddrs(&ifap) < 0) {
+        error_setg_errno(errp, errno, "getifaddrs failed");
+        goto error;
+    }
+
+    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+        GuestNetworkInterfaceList *info;
+        GuestIpAddressList **address_list = NULL, *address_item = NULL;
+        GuestNetworkInterfaceStat  *interface_stat = NULL;
+        char addr4[INET_ADDRSTRLEN];
+        char addr6[INET6_ADDRSTRLEN];
+        int sock;
+        struct ifreq ifr;
+        // struct ifnet ifp;
+        // struct if_data ifd;
+        // unsigned char *mac_addr;
+        char mac_addr[18]="00:00:00:00:00:00"; // = char[18];
+        void *p;
+
+        g_debug("Processing %s interface", ifa->ifa_name);
+
+        info = guest_find_interface(head, ifa->ifa_name);
+
+        if (!info) {
+            info = g_malloc0(sizeof(*info));
+            info->value = g_malloc0(sizeof(*info->value));
+            info->value->name = g_strdup(ifa->ifa_name);
+
+            if (!cur_item) {
+                head = cur_item = info;
+            } else {
+                cur_item->next = info;
+                cur_item = info;
+            }
+        }
+
+        if (!info->value->has_hardware_address &&
+            ifa->ifa_flags & SIOCGHWADDR) {
+            /* we haven't obtained HW address yet */
+            sock = socket(PF_INET, SOCK_STREAM, 0);
+            if (sock == -1) {
+                error_setg_errno(errp, errno, "failed to create socket");
+                goto error;
+            }
+            close(sock);
+
+            memset(&ifr, 0, sizeof(ifr));
+            pstrcpy(ifr.ifr_name, IF_NAMESIZE, info->value->name);
+            // memset(&ifp, 0, sizeof(ifp));
+            // memset(&ifd, 0, sizeof(ifd));
+
+            if (ifa->ifa_addr->sa_family == AF_LINK) {
+            	struct sockaddr_dl *sdl =
+            			(struct sockaddr_dl *)ifa->ifa_addr;
+
+                info->value->has_hardware_address = false;
+
+                if (sdl->sdl_type == IFT_ETHER &&
+                		sdl->sdl_alen == ETHER_ADDR_LEN) {
+                        snprintf(mac_addr, 18, "%s", ether_ntoa((struct ether_addr *)LLADDR(sdl)));
+                        info->value->has_hardware_address = true;
+                }
+                else
+                {
+                    info->value->has_hardware_address = true;
+                }
+                info->value->hardware_address = g_strdup_printf("%s", mac_addr);
+             }
+
+        }
+
+        if (ifa->ifa_addr &&
+            ifa->ifa_addr->sa_family == AF_INET) {
+            /* interface with IPv4 address */
+            p = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
+            if (!inet_ntop(AF_INET, p, addr4, sizeof(addr4))) {
+                error_setg_errno(errp, errno, "inet_ntop failed");
+                goto error;
+            }
+
+            address_item = g_malloc0(sizeof(*address_item));
+            address_item->value = g_malloc0(sizeof(*address_item->value));
+            address_item->value->ip_address = g_strdup(addr4);
+            address_item->value->ip_address_type = GUEST_IP_ADDRESS_TYPE_IPV4;
+
+            if (ifa->ifa_netmask) {
+                /* Count the number of set bits in netmask.
+                 * This is safe as '1' and '0' cannot be shuffled in netmask. */
+                p = &((struct sockaddr_in *)ifa->ifa_netmask)->sin_addr;
+                address_item->value->prefix = ctpop32(((uint32_t *) p)[0]);
+            }
+        } else if (ifa->ifa_addr &&
+                   ifa->ifa_addr->sa_family == AF_INET6) {
+            /* interface with IPv6 address */
+            p = &((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
+            if (!inet_ntop(AF_INET6, p, addr6, sizeof(addr6))) {
+                error_setg_errno(errp, errno, "inet_ntop failed");
+                goto error;
+            }
+
+            address_item = g_malloc0(sizeof(*address_item));
+            address_item->value = g_malloc0(sizeof(*address_item->value));
+            address_item->value->ip_address = g_strdup(addr6);
+            address_item->value->ip_address_type = GUEST_IP_ADDRESS_TYPE_IPV6;
+
+            if (ifa->ifa_netmask) {
+                /* Count the number of set bits in netmask.
+                 * This is safe as '1' and '0' cannot be shuffled in netmask. */
+                p = &((struct sockaddr_in6 *)ifa->ifa_netmask)->sin6_addr;
+                address_item->value->prefix =
+                    ctpop32(((uint32_t *) p)[0]) +
+                    ctpop32(((uint32_t *) p)[1]) +
+                    ctpop32(((uint32_t *) p)[2]) +
+                    ctpop32(((uint32_t *) p)[3]);
+            }
+        }
+
+        if (!address_item) {
+            continue;
+        }
+
+        address_list = &info->value->ip_addresses;
+
+        while (*address_list && (*address_list)->next) {
+            address_list = &(*address_list)->next;
+        }
+
+        if (!*address_list) {
+            *address_list = address_item;
+        } else {
+            (*address_list)->next = address_item;
+        }
+
+        info->value->has_ip_addresses = true;
+
+        if (!info->value->has_statistics) {
+            interface_stat = g_malloc0(sizeof(*interface_stat));
+            if (guest_get_network_stats(info->value->name,
+                interface_stat) == -1) {
+                info->value->has_statistics = false;
+                g_free(interface_stat);
+            } else {
+                info->value->statistics = interface_stat;
+                info->value->has_statistics = true;
+            }
+        }
+    }
+
+    freeifaddrs(ifap);
+    return head;
+
+error:
+    freeifaddrs(ifap);
+    qapi_free_GuestNetworkInterfaceList(head);
+    return NULL;
+}
+#endif // BSD_GUEST_AGENT
+
+#ifndef BSD_GUEST_AGENT
 GuestLogicalProcessorList *qmp_guest_get_vcpus(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
     return NULL;
 }
+#else
+GuestLogicalProcessorList *qmp_guest_get_vcpus(Error **errp)
+{
+    int64_t current;
+    GuestLogicalProcessorList *head, **link;
+    long sc_max;
+    Error *local_err = NULL;
+    int				Query[2];
+    int				NumCpu = 0;
+    size_t			Length = sizeof(NumCpu);
+    Query[0] = CTL_HW;
+    Query[1] = HW_NCPU;
 
+    current = 0;
+    head = NULL;
+    link = &head;
+    if (sysctl(Query, 2, &NumCpu, &Length, NULL, 0) == -1) {
+        error_setg(errp, "sysctl get CTL_HW.HW_NCPU failed");
+    }
+    sc_max = NumCpu;
+
+    while (local_err == NULL && current < sc_max) {
+        GuestLogicalProcessor *vcpu;
+        GuestLogicalProcessorList *entry;
+        int64_t id = current++;
+        // char *path = g_strdup_printf("/sys/devices/system/cpu/cpu%" PRId64 "/",
+        //                              id);
+
+        // if (g_file_test(path, G_FILE_TEST_EXISTS)) {
+        vcpu = g_malloc0(sizeof *vcpu);
+        vcpu->logical_id = id;
+        vcpu->has_can_offline = false; /* lolspeak ftw */
+        vcpu->online = true;
+        vcpu->can_offline = false;
+        // transfer_vcpu(vcpu, true, path, &local_err);
+        entry = g_malloc0(sizeof *entry);
+        entry->value = vcpu;
+        *link = entry;
+        link = &entry->next;
+        // }
+        // g_free(path);
+    }
+
+    if (local_err == NULL) {
+        /* there's no guest with zero VCPUs */
+        g_assert(head != NULL);
+        return head;
+    }
+
+    qapi_free_GuestLogicalProcessorList(head);
+    error_propagate(errp, local_err);
+    return NULL;
+}
+#endif // BSD_GUEST_AGENT
+
 int64_t qmp_guest_set_vcpus(GuestLogicalProcessorList *vcpus, Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
     return -1;
 }
 
+#ifndef BSD_GUEST_AGENT
 void qmp_guest_set_user_password(const char *username,
                                  const char *password,
                                  bool crypted,
@@ -2651,7 +2924,114 @@ void qmp_guest_set_user_password(const char *username,
 {
     error_setg(errp, QERR_UNSUPPORTED);
 }
+#else
+void qmp_guest_set_user_password(const char *username,
+                                 const char *password,
+                                 bool crypted,
+                                 Error **errp)
+{
+    Error *local_err = NULL;
+    char *pw_path = NULL;
+    pid_t pid;
+    int status;
+    int datafd[2] = { -1, -1 };
+    char *rawpasswddata = NULL;
+    size_t rawpasswdlen;
+    char *chpasswddata = NULL;
+    size_t chpasswdlen;
 
+    rawpasswddata = (char *)qbase64_decode(password, -1, &rawpasswdlen, errp);
+    if (!rawpasswddata) {
+        return;
+    }
+
+    rawpasswddata = g_renew(char, rawpasswddata, rawpasswdlen + 1);
+    rawpasswddata[rawpasswdlen] = '\0';
+
+    if (strchr(rawpasswddata, '\n')) {
+        error_setg(errp, "forbidden characters in raw password");
+        goto out;
+    }
+
+    if (strchr(username, '\n') ||
+        strchr(username, ':')) {
+        error_setg(errp, "forbidden characters in username");
+        goto out;
+    }
+
+    chpasswddata = g_strdup_printf("%s", rawpasswddata);
+    chpasswdlen = strlen(chpasswddata);
+
+    pw_path = g_find_program_in_path("pw");
+
+    if (!pw_path) {
+        error_setg(errp, "cannot find 'pw' program in PATH");
+        goto out;
+    }
+
+    if (pipe(datafd) < 0) {
+        error_setg(errp, "cannot create pipe FDs");
+        goto out;
+    }
+
+    pid = fork();
+    if (pid == 0) {
+        close(datafd[1]);
+        /* child */
+        setsid();
+        dup2(datafd[0], 0);
+        reopen_fd_to_null(1);
+        reopen_fd_to_null(2);
+
+        if (crypted) {
+            execle(pw_path, "pw", "usermod", username, "-H", "0", (char*)NULL, environ);
+        } else {
+            execle(pw_path, "pw", "usermod", username, "-h", "0", (char*)NULL, environ);
+        }
+        _exit(EXIT_FAILURE);
+    } else if (pid < 0) {
+        error_setg_errno(errp, errno, "failed to create child process");
+        goto out;
+    }
+    close(datafd[0]);
+    datafd[0] = -1;
+
+    if (qemu_write_full(datafd[1], chpasswddata, chpasswdlen) != chpasswdlen) {
+        error_setg_errno(errp, errno, "cannot write new account password");
+        goto out;
+    }
+    close(datafd[1]);
+    datafd[1] = -1;
+
+    ga_wait_child(pid, &status, &local_err);
+    if (local_err) {
+        error_propagate(errp, local_err);
+        goto out;
+    }
+
+    if (!WIFEXITED(status)) {
+        error_setg(errp, "child process has terminated abnormally");
+        goto out;
+    }
+
+    if (WEXITSTATUS(status)) {
+        error_setg(errp, "child process has failed to set user password");
+        goto out;
+    }
+
+out:
+    g_free(chpasswddata);
+    g_free(rawpasswddata);
+    g_free(pw_path);
+    if (datafd[0] != -1) {
+        close(datafd[0]);
+    }
+    if (datafd[1] != -1) {
+        close(datafd[1]);
+    }
+}
+#endif // BSD_GUEST_AGENT
+
 GuestMemoryBlockList *qmp_guest_get_memory_blocks(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
@@ -2675,12 +3055,240 @@ GuestMemoryBlockInfo *qmp_guest_get_memory_block_info(
 
 #if !defined(CONFIG_FSFREEZE)
 
+#ifndef BSD_GUEST_AGENT
 GuestFilesystemInfoList *qmp_guest_get_fsinfo(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
     return NULL;
 }
+#else
 
+/* ===================================================================== */
+typedef struct FsMount {
+    char *dirname;
+    char *devtype;
+    char *size;
+    char *used;
+    char *free;
+    char *load;
+    char *mntpoint;
+    unsigned int devmajor, devminor;
+    QTAILQ_ENTRY(FsMount) next;
+} FsMount;
+
+typedef QTAILQ_HEAD(FsMountList, FsMount) FsMountList;
+
+static void free_fs_mount_list(FsMountList *mounts)
+{
+     FsMount *mount, *temp;
+
+     if (!mounts) {
+         return;
+     }
+
+     QTAILQ_FOREACH_SAFE(mount, mounts, next, temp) {
+         QTAILQ_REMOVE(mounts, mount, next);
+         g_free(mount->dirname);
+         g_free(mount->devtype);
+         g_free(mount->size);
+         g_free(mount->used);
+		 g_free(mount->free);
+		 g_free(mount->load);
+		 g_free(mount->mntpoint);
+         g_free(mount);
+     }
+}
+
+
+#define BUFSIZE 2048
+
+static void build_fs_mount_list(FsMountList *mounts, Error **errp)
+{
+    FsMount *mount;
+    char const *dfcmd = "/bin/df -hT";
+    //char buf[BUFSIZE];
+
+    FILE *fp;
+    char *line = NULL;
+    //, *dash;
+    size_t n;
+    int ret;
+    //, dir_s, dir_e, type_s, type_e, dev_s, dev_e;
+    char dev_name[30], fstype[10], size[10], used[10], free[10], load[10], mounted[30];
+    //int dev_name, fstype, size, used, free, load, mounted;
+
+    if ((fp = popen(dfcmd, "r")) == NULL) {
+    	g_debug("Cannot open '%s'!!\n", dfcmd);
+        return;
+    }
+	while (getline(&line, &n, fp) != -1) {
+		//g_debug("line '%s'", line);
+		ret = sscanf(line, "%s%s%s%s%s%s%s",
+                     dev_name, fstype, size, used, free, load, mounted);
+		if (g_str_equal(dev_name, "Filesystem")
+				||g_str_equal(fstype,"devfs")
+				||g_str_equal(fstype,"procfs")
+				||g_str_equal(fstype,"fdescfs")) {
+			continue;
+		}
+		//g_debug("ret '%d'", ret);
+
+		if (ret < 7) {
+            continue;
+        }
+        mount = g_new0(FsMount, 1);
+        mount->dirname = g_strdup(dev_name);
+        mount->devtype = g_strdup(fstype);
+        mount->free = g_strdup(free);
+        mount->load = g_strdup(load);
+        mount->size = g_strdup(size);
+        mount->used = g_strdup(used);
+        mount->mntpoint = g_strdup(mounted);
+        mount->devmajor = 0;
+        mount->devminor = 0;
+
+        QTAILQ_INSERT_TAIL(mounts, mount, next);
+    }
+    //free(line);
+
+    fclose(fp);
+}
+
+/* ======================================================= */
+
+
+/* Return a list of the disk device(s)' info which @mount lies on */
+static GuestFilesystemInfo *build_guest_fsinfo(struct FsMount *mount,
+                                               Error **errp)
+{
+    GuestFilesystemInfo *fs = g_malloc0(sizeof(*fs));
+    struct statvfs buf;
+    unsigned long used, nonroot_total, fr_size;
+
+    fs->name = g_strdup(mount->dirname);
+    fs->mountpoint = g_strdup(mount->mntpoint);
+    fs->type = g_strdup(mount->devtype);
+
+    /*
+     * if you need extended structure like this
+     *
+    {
+      "name": "/dev/vtbd0p2",
+      "total-bytes": 9079570432,
+      "mountpoint": "/",
+      "disk": [
+        {
+          "serial": "serial",
+          "bus-type": "virtio",
+          "bus": 0,
+          "unit": 0,
+          "pci-controller": {
+            "bus": 0,
+            "slot": 0,
+            "domain": 0,
+            "function": 0
+          },
+          "dev": "/dev/vtbd0p2",
+          "target": 0
+        }
+      ],
+      "used-bytes": 7378640896,
+      "type": "ufs"
+    }
+
+    instead
+
+    {
+      "name": "/dev/vtbd0p2",
+      "total-bytes": 9079570432,
+      "mountpoint": "/",
+      "disk": [],
+      "used-bytes": 7378747392,
+      "type": "ufs"
+    }
+
+    uncomment next block with pciaddr
+
+    */
+    /*
+    GuestPCIAddress *pciaddr = NULL;
+    GuestDiskAddressList *list = NULL;
+    GuestDiskAddress *disk;
+    pciaddr = g_malloc0(sizeof(*pciaddr));
+    pciaddr->domain = 0;
+    pciaddr->bus = 0;
+    pciaddr->slot = 0;
+    pciaddr->function = 0;
+
+    disk = g_malloc0(sizeof(*disk));
+    disk->pci_controller = pciaddr;
+
+    disk->dev = g_strdup(mount->dirname);
+    disk->has_dev = true;
+    disk->bus_type = GUEST_DISK_BUS_TYPE_VIRTIO;
+    disk->serial = g_strdup("serial");
+    disk->has_serial = true;
+
+    list = g_malloc0(sizeof(*list));
+    list->value = disk;
+
+    list->next = fs->disk;
+    fs->disk = list;
+	*/
+
+    if (statvfs(fs->mountpoint, &buf) == 0) {
+        fr_size = buf.f_frsize;
+        used = buf.f_blocks - buf.f_bfree;
+        nonroot_total = used + buf.f_bavail;
+        fs->used_bytes = used * fr_size;
+        fs->total_bytes = nonroot_total * fr_size;
+
+        fs->has_total_bytes = true;
+        fs->has_used_bytes = true;
+    }
+
+    //g_free(devpath);
+
+    return fs;
+}
+
+GuestFilesystemInfoList *qmp_guest_get_fsinfo(Error **errp)
+{
+    FsMountList mounts;
+    struct FsMount *mount;
+    GuestFilesystemInfoList *new, *ret = NULL;
+    Error *local_err = NULL;
+
+    QTAILQ_INIT(&mounts);
+
+    //g_debug("Entering to guest_get_fsinfo");
+    build_fs_mount_list(&mounts, &local_err);
+    if (local_err) {
+        error_propagate(errp, local_err);
+        return NULL;
+    }
+
+
+    QTAILQ_FOREACH(mount, &mounts, next) {
+        //g_debug("Building guest fsinfo for '%s'", mount->dirname);
+        //g_debug("Devtype '%s'", mount->devtype);
+        new = g_malloc0(sizeof(*ret));
+        new->value = build_guest_fsinfo(mount, &local_err);
+        new->next = ret;
+        ret = new;
+        if (local_err) {
+            error_propagate(errp, local_err);
+            qapi_free_GuestFilesystemInfoList(ret);
+            ret = NULL;
+            break;
+        }
+    }
+
+    free_fs_mount_list(&mounts);
+    return ret;
+}
+#endif // BSD_GUEST_AGENT
+
 GuestFsfreezeStatus qmp_guest_fsfreeze_status(Error **errp)
 {
     error_setg(errp, QERR_UNSUPPORTED);
@@ -2726,6 +3334,7 @@ GList *ga_command_blacklist_init(GList *blacklist)
 {
 #if !defined(__linux__)
     {
+#ifndef BSD_GUEST_AGENT
         const char *list[] = {
             "guest-suspend-disk", "guest-suspend-ram",
             "guest-suspend-hybrid", "guest-network-get-interfaces",
@@ -2733,6 +3342,15 @@ GList *ga_command_blacklist_init(GList *blacklist)
             "guest-get-memory-blocks", "guest-set-memory-blocks",
             "guest-get-memory-block-size", "guest-get-memory-block-info",
             NULL};
+#else
+    	const char *list[] = {
+            "guest-suspend-disk", "guest-suspend-ram",
+            "guest-suspend-hybrid",
+            "guest-set-vcpus",
+            "guest-get-memory-blocks", "guest-set-memory-blocks",
+            "guest-get-memory-block-size", "guest-get-memory-block-info",
+            NULL};
+#endif // BSD_GUEST_AGENT
         char **p = (char **)list;
 
         while (*p) {
@@ -2743,10 +3361,17 @@ GList *ga_command_blacklist_init(GList *blacklist)
 
 #if !defined(CONFIG_FSFREEZE)
     {
+#ifndef BSD_GUEST_AGENT
         const char *list[] = {
             "guest-get-fsinfo", "guest-fsfreeze-status",
             "guest-fsfreeze-freeze", "guest-fsfreeze-freeze-list",
             "guest-fsfreeze-thaw", "guest-get-fsinfo", NULL};
+#else
+        const char *list[] = {
+            "guest-fsfreeze-status",
+            "guest-fsfreeze-freeze", "guest-fsfreeze-freeze-list",
+            "guest-fsfreeze-thaw",  NULL};
+#endif // BSD_GUEST_AGENT
         char **p = (char **)list;
 
         while (*p) {
