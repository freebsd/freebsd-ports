--- ./src/core/f1ltcore.h.orig	2013-03-22 16:57:29.000000000 -0700
+++ ./src/core/f1ltcore.h	2013-03-22 16:59:40.000000000 -0700
@@ -74,7 +74,7 @@
         QString prefix = STR(INSTALL_PREFIX);
         QDir dir;
         if (dir.exists(prefix))
-            return prefix + "/share/season.dat";
+            return prefix + "/share/F1LT/season.dat";
         else
             return programHomeDir() + "/season.dat";
 #endif
@@ -88,7 +88,7 @@
         QString prefix = STR(INSTALL_PREFIX);
         QDir dir;
         if (dir.exists(prefix))
-            return prefix + "/share/trackdata.dat";
+            return prefix + "/share/F1LT/trackdata.dat";
         else
             return programHomeDir() + "/trackdata.dat";
 #endif
@@ -102,7 +102,7 @@
         QString prefix = STR(INSTALL_PREFIX);
         QDir dir;
         if (dir.exists(prefix))
-            return prefix + "/share/trackrecords.dat";
+            return prefix + "/share/F1LT/trackrecords.dat";
         else
             return programHomeDir() + "/trackrecords.dat";
 #endif
