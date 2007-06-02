--- xdvik-22.40y1/texk/xdvik/xdvi.h.orig	Sat Jun  2 13:34:09 2007
+++ xdvik-22.40y1/texk/xdvik/xdvi.h	Sat Jun  2 13:34:42 2007
@@ -349,7 +349,7 @@
 
 typedef	unsigned char	ubyte;
 
-#if	NeedWidePrototypes
+#if	1
 typedef	unsigned int	wide_ubyte;
 typedef	int		wide_bool;
 #define	WIDENINT	(int)
