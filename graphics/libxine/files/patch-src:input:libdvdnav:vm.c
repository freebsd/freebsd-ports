--- src/input/libdvdnav/vm.c.orig	Sat Jan 11 23:43:55 2003
+++ src/input/libdvdnav/vm.c	Sat Jan 11 23:45:47 2003
@@ -48,6 +48,8 @@
 
 #define STRICT
 
+#define off64_t off_t
+#define lseek64 lseek
 
 /* Local prototypes */
 
