--- src/Config.h.orig	2016-07-27 02:21:28 UTC
+++ src/Config.h
@@ -35,7 +35,7 @@
 #endif
 //VersionInfoEnd
 
-//#define IGNORE_UPDATES //uncomment this for mods, to not get any update notifications
+#define IGNORE_UPDATES //uncomment this for mods, to not get any update notifications
 
 #if !(defined(MACOSX) && defined(DEBUG))
 #define HIGH_QUALITY_RESAMPLE			//High quality image resampling, slower but much higher quality than my terribad linear interpolation
