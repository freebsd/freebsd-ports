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
@@ -8423,6 +8423,11 @@
     nb_nics = 0;
     /* default mac address of the first network interface */
 
+#ifdef __FreeBSD__
+    if (modfind("aio") == -1)
+        fprintf(stderr, "warning: aio not (kld)loaded, may cause `Invalid system call' traps on disk IO\n");
+#endif
+
     optind = 1;
     for(;;) {
         if (optind >= argc)
@@ -8784,6 +8784,7 @@
 #ifdef TARGET_ARM
             case QEMU_OPTION_old_param:
                 old_param = 1;
+                break;
 #endif
             case QEMU_OPTION_clock:
                 configure_alarms(optarg);
