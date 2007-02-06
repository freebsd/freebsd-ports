--- src/rtaudioplayback/rtaudioplayback.pro.orig	Tue Feb  6 00:13:48 2007
+++ src/rtaudioplayback/rtaudioplayback.pro	Tue Feb  6 00:14:18 2007
@@ -25,10 +25,6 @@
 
 QT += gui xml network
 
-unix:!mac {
-   LIBS += -lasound
-}
-
 win32 {
    LIBS += -lwinmm -ldsound -lole32 -lgdi32 -luser32 -lshfolder
    INCLUDEPATH += "c:\program files\microsoft directx sdk (april 2006)\include"
