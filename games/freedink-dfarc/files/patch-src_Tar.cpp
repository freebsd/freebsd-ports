--- src/Tar.cpp.orig	2015-01-24 23:59:53.000000000 -0800
+++ src/Tar.cpp	2015-01-25 00:51:23.000000000 -0800
@@ -33,7 +33,7 @@
 #include <wx/filename.h>
 
 #include <math.h>
-#include <ext/stdio_filebuf.h>
+#include <fstream>
 #include <sstream>
 #include <sys/types.h>
 
@@ -477,9 +477,9 @@
 
 
     // Open the file here so it doesn't error after changing.
-    wxFile wx_In(mFilePath, wxFile::read);
+    std::ifstream f_In (mFilePath, std::ifstream::in | std::ifstream::binary);
 
-    if(!wx_In.IsOpened())
+    if(!f_In.is_open())
     {
       lError = 1;
       wxLogFatalError(_("Error: File '%s' not found!  Cannot extract data."), mFilePath.c_str());
@@ -499,13 +499,11 @@
     ::wxSetWorkingDirectory(destdir);
 
     // Put the data in the directories.
-    __gnu_cxx::stdio_filebuf<char> filebuf(wx_In.fd(), std::ios::in);
-    std::istream f_In(&filebuf);
     if (ExtractData(f_In, destdir, aProgressDialog) != 0)
     {
         lError = 1;
     }
-    wx_In.Close();
+    f_In.close();
 
 
     // We're done.  Move back.
@@ -571,15 +569,13 @@
             if (lLastCharacter != '\\' && lLastCharacter != '/')
             {
                 // Open the file.
-                wxFile wx_Out(lCurrentFilePath, wxFile::write);
-		if (!wx_Out.IsOpened())
+                std::ofstream lStreamOut(lCurrentFilePath, std::ifstream::out | std::ifstream::binary);
+		if (!lStreamOut.is_open())
                 {
 		    wxLogError(_("Error: Improperly archived file '%s'.  Skipping."), lCurrentFilePath);
                     lError = 1;
                     continue;
                 }
-		__gnu_cxx::stdio_filebuf<char> filebuf(wx_Out.fd(), std::ios::out);
-		std::ostream lStreamOut(&filebuf);
                 
 		aTarStreamIn.seekg(lCurrentTarRecord.iFilePosBegin, std::ios::beg);
 		long remaining = lCurrentTarRecord.iFileSize;
@@ -595,7 +591,7 @@
                 
                 // Close up.
                 lStreamOut.flush();
-                wx_Out.Close();
+                lStreamOut.close();
             }
             
             // Update progress
