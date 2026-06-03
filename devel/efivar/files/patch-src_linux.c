--- src/linux.c.orig	2024-01-31 20:08:46 UTC
+++ src/linux.c
@@ -12,17 +12,30 @@
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
-#include <linux/ethtool.h>
-#include <linux/version.h>
-#include <linux/sockios.h>
+#if defined(__linux__)
+#  include <linux/ethtool.h>
+#  include <linux/version.h>
+#  include <linux/sockios.h>
+#elif defined(__FreeBSD__)
+#  include <net/if.h>
+#  include <net/if_dl.h>
+#endif
 #include <net/if.h>
-#include <scsi/scsi.h>
+#if defined(__linux__)
+#  include <scsi/scsi.h>
+#endif
 #include <stdbool.h>
 #include <stdio.h>
+#if defined(__FreeBSD__)
+#  include <sys/disk.h>
+#  undef LIST_HEAD
+#endif
 #include <sys/ioctl.h>
 #include <sys/mount.h>
 #include <sys/socket.h>
-#include <sys/sysmacros.h>
+#if defined(__linux__)
+#  include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/stat.h>
@@ -630,6 +643,7 @@ make_blockdev_path(uint8_t *buf, ssize_t size, struct 
 	return off;
 }
 
+#if defined(__linux__)
 ssize_t HIDDEN
 make_mac_path(uint8_t *buf, ssize_t size, const char * const ifname)
 {
@@ -693,7 +707,48 @@ err:
 	        close(fd);
 	return ret;
 }
+#elif defined(__FreeBSD__)
+ssize_t HIDDEN
+make_mac_path(uint8_t *buf, ssize_t size, const char * const ifname)
+{
+	int fd;
+	struct ifreq ifr;
+	struct sockaddr_dl *sdl;
+	ssize_t ret = -1;
 
+	if (!buf || !ifname)
+		return -1;
+
+	fd = socket(AF_INET, SOCK_DGRAM, 0);
+	if (fd < 0)
+		return -1;
+
+	memset(&ifr, 0, sizeof(ifr));
+	strncpy(ifr.ifr_name, ifname, IFNAMSIZ-1);
+	ifr.ifr_name[IFNAMSIZ-1] = '\0';
+
+	if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
+		close(fd);
+		return -1;
+	}
+
+	// For MAC, use AF_LINK (sockaddr_dl)
+	if (ioctl(fd, SIOCGIFCONF, &ifr) < 0) {
+		close(fd);
+		return -1;
+	}
+
+	sdl = (struct sockaddr_dl *)&ifr.ifr_addr;
+	if (sdl->sdl_alen > 0 && sdl->sdl_alen <= size) {
+		memcpy(buf, LLADDR(sdl), sdl->sdl_alen);
+		ret = sdl->sdl_alen;
+	}
+
+	close(fd);
+	return ret;
+}
+#endif
+
 /************************************************************
  * get_sector_size
  * Requires:
@@ -707,7 +762,12 @@ get_sector_size(int filedes)
 {
 	int rc, sector_size = 512;
 
+	(void)filedes;
+#if defined(__linux__)
 	rc = ioctl(filedes, BLKSSZGET, &sector_size);
+#elif defined(__FreeBSD__)
+	rc = ioctl(filedes, DIOCGSECTORSIZE, &sector_size);
+#endif
 	if (rc)
 	        sector_size = 512;
 	return sector_size;
