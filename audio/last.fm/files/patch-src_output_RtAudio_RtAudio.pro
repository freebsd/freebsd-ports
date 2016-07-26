--- src/output/RtAudio/RtAudio.pro.orig	2008-04-09 11:46:29 UTC
+++ src/output/RtAudio/RtAudio.pro
@@ -8,10 +8,6 @@ include( ../../../definitions.pro.inc )
 HEADERS = rtaudioplayback.h
 SOURCES = rtaudioplayback.cpp rtaudio/RtAudio.cpp
 
-unix:!mac {
-    LIBS += -lasound
-}
-
 win32 {
    LIBS += -lwinmm -Ldsound -ldsound -lole32 -lgdi32 -luser32
    INCLUDEPATH += dsound
