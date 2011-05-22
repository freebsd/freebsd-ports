--- src/VBox/Additions/x11/x11include/7.1/xorg/xf86_ansic.h.orig	2011-01-25 20:04:06.000000000 +0100
+++ src/VBox/Additions/x11/x11include/7.1/xorg/xf86_ansic.h	2011-01-25 20:04:15.000000000 +0100
@@ -269,7 +269,6 @@
 extern int xf86open(const char*, int,...);
 extern int xf86close(int);
 extern long xf86lseek(int, long, int);
-extern int xf86ioctl(int, unsigned long, pointer);
 extern xf86ssize_t xf86read(int, void *, xf86size_t);
 extern xf86ssize_t xf86write(int, const void *, xf86size_t);
 extern void* xf86mmap(void*, xf86size_t, int, int, int, xf86size_t /* off_t */);
