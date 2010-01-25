--- ./snd_openal/snd_main.c.orig	2009-12-26 19:07:05.000000000 +0100
+++ ./snd_openal/snd_main.c	2009-12-26 19:07:13.000000000 +0100
@@ -231,7 +231,7 @@
 #define ALDRIVER "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #define ALDEVICE_DEFAULT NULL
 #else
-#define ALDRIVER "libopenal.so.0"
+#define ALDRIVER "libopenal.so"
 #define ALDEVICE_DEFAULT NULL
 #endif
 
