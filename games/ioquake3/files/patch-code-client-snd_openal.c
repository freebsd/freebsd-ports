--- code/client/snd_openal.c.orig	2009-03-15 12:39:53 UTC
+++ code/client/snd_openal.c
@@ -1719,7 +1719,7 @@ static cvar_t *s_alCapture;
 #elif defined(MACOS_X)
 #define ALDRIVER_DEFAULT "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.0"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
