--- code/client/snd_openal.c.orig	2009-12-26 18:10:44.000000000 +0100
+++ code/client/snd_openal.c	2009-12-26 18:11:00.000000000 +0100
@@ -1719,7 +1719,7 @@
 #elif defined(MACOS_X)
 #define ALDRIVER_DEFAULT "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.0"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
