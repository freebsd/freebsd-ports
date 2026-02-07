--- extension.c.orig	2025-11-23 16:41:16 UTC
+++ extension.c
@@ -20,8 +20,6 @@
 #include <pthread.h>
 #include <sys/time.h>
 #include <sys/mman.h>
-#include <linux/fb.h>
-#include <linux/fb.h>
 #include <sys/ioctl.h>
 
 
@@ -131,6 +129,7 @@ void init_exsubr(void)
     def_subr("RECV-SOCKET", f_recv_socket);
     def_subr("CLOSE-SOCKET", f_close_socket);
 
+#if 0
     def_subr("GR-OPEN", f_gr_open);
     def_subr("GR-CLOSE", f_gr_close);
     def_subr("GR-CLS", f_gr_cls);
@@ -138,6 +137,7 @@ void init_exsubr(void)
     def_subr("GR-CIRCLE", f_gr_circle);
     def_subr("GR-RECT", f_gr_rect);
     def_subr("GR-LINE", f_gr_line);
+#endif
 
 #ifdef __rpi__
     def_subr("WIRINGPI-SETUP-GPIO", f_wiringpi_setup_gpio);
@@ -1891,6 +1891,7 @@ int f_close_socket(int arglist, int th)
 }
 
 
+# if 0
 //-------/dev/fb0------------------------
 
 #define BLACK       0x000000  
@@ -2201,3 +2202,4 @@ int f_gr_line(int arglist, int th)
     fb_draw_line(GET_INT(arg1),GET_INT(arg2),GET_INT(arg3),GET_INT(arg4),color_to_number(arg5));
     return(T);
 }
+#endif
