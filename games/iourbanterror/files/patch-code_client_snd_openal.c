--- code/client/snd_openal.c.orig	2009-12-26 18:12:52.000000000 +0100
+++ code/client/snd_openal.c	2009-12-26 18:13:00.000000000 +0100
@@ -1676,7 +1676,7 @@
 #elif defined(MACOS_X)
 #define ALDRIVER_DEFAULT "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.0"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
