--- parts/outputviews/appoutputviewpart.cpp.orig	Thu Nov  4 07:43:17 2004
+++ parts/outputviews/appoutputviewpart.cpp	Tue Jun 22 19:28:13 2004
@@ -99,7 +99,7 @@
         cmd += program;
         cmd += "; echo \"";
         cmd += i18n("Press Enter to continue!");
-        cmd += "\";read'";
+        cmd += "\";read dummy'";
     } else
         cmd = program;
 
