--- src/FPGAcontrols_wxgui/FPGAcontrols_wxgui.cpp.orig	2020-10-29 09:52:56 UTC
+++ src/FPGAcontrols_wxgui/FPGAcontrols_wxgui.cpp
@@ -166,7 +166,7 @@ int ReadWFM(const wxString filename, std::vector<int16
     if( fpin.IsOpened() == false)
     {
 #ifndef NDEBUG
-        lime::debug("WFM reading: Input file can not be opened (%s)", filename);
+        lime::debug("WFM reading: Input file can not be opened (%s)", filename.mb_str().data());
 #endif
         return -1;
     }
