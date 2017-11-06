--- src/Audacity.h.orig	2017-06-16 13:26:40 UTC
+++ src/Audacity.h
@@ -24,13 +24,6 @@
 #ifndef __AUDACITY_H__
 #define __AUDACITY_H__
 
-// If building with GNU compiler, then must be 4.9 or later.
-// TODO: This would be much nicer as a standalone test in configure.ac
-#if !defined(__APPLE__) && defined __GNUC__ && ( __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))
-#error insufficient compiler
-#endif
-
-
 // We only do alpha builds and release versions.
 // Most of the time we're in development, so IS_ALPHA should be defined
 // to 1.
