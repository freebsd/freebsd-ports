--- include/lightning.h.orig	2013-09-02 13:38:10.000000000 +0300
+++ include/lightning.h	2013-09-02 14:57:27.000000000 +0300
@@ -38,7 +38,7 @@
 #    define __WORDSIZE		WORDSIZE
 #  elif defined(__SIZEOF_POINTER__)		/* ppc aix */
 #    define __WORDSIZE		(__SIZEOF_POINTER__ << 3)
-#  elif defined(_ILP32)				/* hppa hp-ux */
+#  elif defined(_ILP32) || defined(__i386__)	/* hppa hp-ux, i386 gcc 4.2 */
 #    define __WORDSIZE		32
 #  elif defined(_LP64)				/* ia64 hp-ux (with cc +DD64) */
 #    define __WORDSIZE		64
