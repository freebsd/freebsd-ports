--- libs/video/targets/vid_svgalib.c.orig	Fri Aug 20 10:51:02 2004
+++ libs/video/targets/vid_svgalib.c	Fri Aug 20 10:52:52 2004
@@ -82,6 +82,19 @@
 byte	*VGA_pagebase;
 int		 VID_options_items = 0;
 
+#if defined(i386) && defined(__GLIBC__) && (__GLIBC__ < 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 2))
+void
+outb (unsigned char val, unsigned short port)
+{
+	asm ("outb %b0, %w1" : :"a"(val), "d"(port));
+}
+#elif defined(__FreeBSD__)
+static inline void
+outb (unsigned char value, unsigned short port)
+{
+	__asm__ __volatile__ ("outb %b0,%w1"::"a" (value), "d" (port));
+}
+#endif
 
 void
 D_BeginDirectRect (int x, int y, byte * pbitmap, int width, int height)
@@ -487,16 +500,3 @@
 	return false;
 }
 
-#if defined(i386) && defined(__GLIBC__) && (__GLIBC__ < 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 2))
-void
-outb (unsigned char val, unsigned short port)
-{
-	asm ("outb %b0, %w1" : :"a"(val), "d"(port));
-}
-#elif defined(__FreeBSD__)
-static inline void
-outb (unsigned char value, unsigned short port)
-{
-	__asm__ __volatile__ ("outb %b0,%w1"::"a" (value), "d" (port));
-}
-#endif
