--- kmamerun/preferences.cpp.orig	Wed Feb 26 21:04:52 2003
+++ kmamerun/preferences.cpp	Wed Feb 26 21:05:35 2003
@@ -256,7 +256,7 @@
         prefGeneral.logdir = "/tmp";
     mamecmd = prefGeneral.mamecmd;
     logdir = prefGeneral.logdir;
-    prefGeneral.spooldir = "";
+    prefGeneral.hiscoredir = "";
     prefGeneral.cheat = 0;
     prefGeneral.version = 37;
     prefGeneral.check_romsets = false;
@@ -368,9 +368,9 @@
             sscanf(line.data(),"%*s%s",buf);
             prefGeneral.rompath = buf;
             prefGeneral.version = 34;
-        } else if (str == "spooldir") {
+        } else if (str == "hiscoredir") {
             sscanf(line.data(),"%*s%s",buf);
-            prefGeneral.spooldir = buf;
+            prefGeneral.hiscoredir = buf;
         } else if (str == "screenshotdir") {
             sscanf(line.data(),"%*s%s",buf);
             prefGeneral.screenshotdir = buf;
