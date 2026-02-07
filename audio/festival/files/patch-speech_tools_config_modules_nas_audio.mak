$NetBSD: patch-ag,v 1.1 2000/05/05 20:54:57 hubertf Exp $

--- speech_tools/config/modules/nas_audio.mak.orig	Fri May  5 20:55:15 2000
+++ speech_tools/config/modules/nas_audio.mak	Fri May  5 20:58:07 2000
@@ -45,6 +45,6 @@
 AUDIO_DEFINES += -DSUPPORT_NAS
 AUDIO_INCLUDES += -I$(NAS_INCLUDE)
 MODULE_LIBS += -L$(NAS_LIB) -laudio 
-MODULE_EXTRA_LIBS += -L$(X11_LIB) -lX11 -lXt
+MODULE_EXTRA_LIBS += -L$(X11_LIB) -Wl,-R $(X11_LIB) -lX11 -lXt
 
 
