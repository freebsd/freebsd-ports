Index: qemu/vl.c
@@ -40,6 +40,10 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <dirent.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <libutil.h>
+#endif
 #ifdef _BSD
 #include <sys/stat.h>
 #ifndef __APPLE__
@@ -1280,7 +1284,7 @@
     return chr;
 }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 CharDriverState *qemu_chr_open_pty(void)
 {
     char slave_name[1024];
