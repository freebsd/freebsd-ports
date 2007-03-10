Index: qemu/vl.c
@@ -1510,7 +1510,7 @@
     return chr;
 }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 static CharDriverState *qemu_chr_open_pty(void)
 {
     struct termios tty;
@@ -1904,6 +1907,7 @@
     return chr;
 }
 
+#if defined(__linux__)
 typedef struct {
     int fd;
     int mode;
@@ -1727,6 +1728,7 @@
     chr->chr_ioctl = pp_ioctl;
     return chr;
 }
+#endif /* defined(__linux__) */
 
 #else
 CharDriverState *qemu_chr_open_pty(void)
