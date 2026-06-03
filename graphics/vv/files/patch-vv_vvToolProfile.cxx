--- vv/vvToolProfile.cxx.orig	2026-03-02 00:20:47 UTC
+++ vv/vvToolProfile.cxx
@@ -509,7 +509,7 @@ void vvToolProfile::SaveAs()
         std::ofstream fileOpen(mTextFileName.c_str(), std::ofstream::trunc);
   
         if(!fileOpen) {
-            cerr << "Error during saving" << endl;
+            std::cerr << "Error during saving" << std::endl;
             QApplication::restoreOverrideCursor();
             close();
             return;
