--- ./GUI/Main.hs.orig	2011-09-05 04:33:21.000000000 +0200
+++ ./GUI/Main.hs	2011-12-07 01:27:00.000000000 +0100
@@ -79,7 +79,6 @@
    | EventFileReload
    | EventFileExport FilePath FileExportFormat
 
--- | EventStateClear
    | EventSetState HECs (Maybe FilePath) String Int Double
 
    | EventShowSidebar Bool
