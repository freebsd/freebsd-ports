$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/awt_LoadLibrary.c	10 Jan 2005 15:09:40 -0000	1.2
+++ ../../j2se/src/solaris/native/sun/awt/awt_LoadLibrary.c	9 Oct 2005 05:34:52 -0000
@@ -195,8 +195,7 @@
             }
         }
         else {
-/* XXXBSD: decide which toolkit to use */
-#if defined(__linux)
+#if defined(__linux) || defined(_ALLBSD_SOURCE)
             /* Default AWT Toolkit on Linux is XAWT. */
             strcpy(p, "/xawt/libmawt");
             XAWT = 1;
