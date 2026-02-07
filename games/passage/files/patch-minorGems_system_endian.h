--- minorGems/system/endian.h.orig	2009-04-03 17:39:19.000000000 +0400
+++ minorGems/system/endian.h	2015-03-27 02:42:33.353630000 +0300
@@ -25,7 +25,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <machine/endian.h>
 
 
