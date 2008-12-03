--- src/hugin1/base_wx/RunStitchPanel.cpp.orig	2008-12-03 14:29:01.000000000 +0200
+++ src/hugin1/base_wx/RunStitchPanel.cpp	2008-12-03 14:31:30.000000000 +0200
@@ -240,6 +240,8 @@
             cmd = wxT("make");  
         }
         cmd += wxT(" ") + args;
+#elif defined __FreeBSD__
+        wxString cmd = wxT("gmake ") + args;  
 #else
         wxString cmd = wxT("make ") + args;  
 #endif
