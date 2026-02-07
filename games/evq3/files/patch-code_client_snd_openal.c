--- code/client/snd_openal.c.orig	2009-12-26 18:05:56.000000000 +0100
+++ code/client/snd_openal.c	2009-12-26 18:06:06.000000000 +0100
@@ -1707,7 +1707,7 @@
 #elif defined(MACOS_X)
 #define ALDRIVER_DEFAULT "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.0"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
