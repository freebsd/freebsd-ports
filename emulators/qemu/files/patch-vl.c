Index: qemu/vl.c
@@ -1510,7 +1510,7 @@
     return chr;
 }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 static CharDriverState *qemu_chr_open_pty(void)
 {
     struct termios tty;
@@ -1665,6 +1665,7 @@
     return chr;
 }
 
+#if defined(__linux__)
 static int pp_ioctl(CharDriverState *chr, int cmd, void *arg)
 {
     int fd = (int)chr->opaque;
@@ -1727,6 +1728,7 @@
     chr->chr_ioctl = pp_ioctl;
     return chr;
 }
+#endif /* defined(__linux__) */
 
 #else
 CharDriverState *qemu_chr_open_pty(void)
