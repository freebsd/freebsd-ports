--- src/UiGuiSystemInfo.cpp.orig	2012-01-01 17:51:34.000000000 +0100
+++ src/UiGuiSystemInfo.cpp	2013-02-17 15:22:00.000000000 +0100
@@ -154,6 +154,17 @@
 
         operatingSystemString = os + "oslevel " + oslevel;
     }
+     else if ( os == "FreeBSD" ) {
+         process.start("uname -n");
+         result = process.waitForFinished(1000);
+         QString name = process.readAllStandardOutput().trimmed();
+ 
+         process.start("uname -v");
+         result = process.waitForFinished(1000);
+         QString oslevel = process.readAllStandardOutput().trimmed();
+ 
+         operatingSystemString = os + " " + name + " " + rev + " " + oslevel + " " + mach;
+    }
     else if ( os == "Linux" ) {
         QString dist;
         QString pseudoname;
