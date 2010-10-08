--- src/io/gfx/video.cpp.orig	2010-10-06 18:26:54.742621897 +0000
+++ src/io/gfx/video.cpp	2010-10-06 18:27:27.564666319 +0000
@@ -139,7 +139,7 @@
 	}
 #endif
 
-#if !defined(WIZ) && (defined(CAANOO) || defined(GP2X))
+#if !defined(WIZ)
 	expose();
 #endif
 
