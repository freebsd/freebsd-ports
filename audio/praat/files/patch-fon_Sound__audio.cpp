--- fon/Sound_audio.cpp.orig	2026-06-09 21:48:47 UTC
+++ fon/Sound_audio.cpp
@@ -37,7 +37,7 @@
 	#include <windows.h>
 	#include <mmsystem.h>
 	#include "winport_off.h"
-#elif defined (linux)
+#elif defined (linux) || defined(UNIX)
 	#include <fcntl.h>
 	#if ! defined (NO_AUDIO)
 		#if defined (__OpenBSD__) || defined (__NetBSD__)
