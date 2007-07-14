--- src/output/RtAudio/RtAudio.pro.orig	Sat Jul 14 09:37:38 2007
+++ src/output/RtAudio/RtAudio.pro	Sat Jul 14 09:37:51 2007
@@ -8,10 +8,6 @@
 HEADERS = rtaudioplayback.h
 SOURCES = rtaudioplayback.cpp rtaudio/RtAudio.cpp
 
-unix:!mac {
-    LIBS += -lasound
-}
-
 win32 {
    LIBS += -lwinmm -Ldsound -ldsound -lole32 -lgdi32 -luser32 -lshfolder
    INCLUDEPATH += dsound
