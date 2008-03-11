Index: qemu/vl.c
@@ -1727,6 +1728,7 @@
     chr->chr_ioctl = pp_ioctl;
     return chr;
 }
+#endif /* defined(__linux__) */
 
 #else
 CharDriverState *qemu_chr_open_pty(void)
@@ -1771,14 +1771,14 @@
     return chr;
 }
 
-#if defined(__linux__) || defined(__sun__)
+#if defined(__linux__) || defined(__sun__) || defined(__FreeBSD__)
 static CharDriverState *qemu_chr_open_pty(void)
 {
     struct termios tty;
     char slave_name[1024];
     int master_fd, slave_fd;
  
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     /* Not satisfying */
     if (openpty(&master_fd, &slave_fd, slave_name, NULL, NULL) < 0) {
         return NULL;
@@ -3036,7 +3036,7 @@
         return qemu_chr_open_pp(filename);
     } else 
 #endif
-#if defined(__linux__) || defined(__sun__)
+#if defined(__linux__) || defined(__sun__) || defined(__FreeBSD__)
     if (strstart(filename, "/dev/", NULL)) {
         return qemu_chr_open_tty(filename);
     } else
