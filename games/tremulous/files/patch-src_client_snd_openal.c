--- ./tremulous-1.1.0-src/src/client/snd_openal.c.orig	2009-12-26 18:56:43.000000000 +0100
+++ ./tremulous-1.1.0-src/src/client/snd_openal.c	2009-12-26 18:56:49.000000000 +0100
@@ -1526,7 +1526,7 @@
 #ifdef _WIN32
 #define ALDRIVER_DEFAULT "OpenAL32.dll"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.0"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
