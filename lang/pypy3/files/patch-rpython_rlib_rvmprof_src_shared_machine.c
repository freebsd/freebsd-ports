--- rpython/rlib/rvmprof/src/shared/machine.c.orig	2017-06-05 20:40:44 UTC
+++ rpython/rlib/rvmprof/src/shared/machine.c
@@ -28,6 +28,8 @@ const char * vmp_machine_os_name(void)
     #endif
 #elif __linux__
     return "linux";
+#elif __FreeBSD__
+    return "freebsd";
 #else
     #error "Unknown compiler"
 #endif
@@ -39,7 +41,7 @@ long vmp_fd_to_path(int fd, char * buffe
     char proffs[24];
     (void)snprintf(proffs, 24, "/proc/self/fd/%d", fd);
     return readlink(proffs, buffer, buffer_len);
-#elif defined(VMPROF_UNIX)
+#elif defined(VMPROF_UNIX) && !defined(__FreeBSD__)
     fcntl(fd, F_GETPATH, buffer);
     return strlen(buffer);
 #endif
