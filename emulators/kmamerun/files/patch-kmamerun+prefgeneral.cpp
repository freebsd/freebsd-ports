--- kmamerun/prefgeneral.cpp.orig	Wed Feb 26 21:05:03 2003
+++ kmamerun/prefgeneral.cpp	Wed Feb 26 21:05:35 2003
@@ -35,7 +35,7 @@
 {
     checkCheat->setChecked(prefs->cheat);
     inputMamedir->setText(prefs->rompath);
-    inputSpooldir->setText(prefs->spooldir);
+    inputHiscoredir->setText(prefs->hiscoredir);
     inputMamecmd->setText(prefs->mamecmd);
     inputLogdir->setText(prefs->logdir);
     inputImagedir->setText(prefs->screenshotdir);
@@ -57,7 +57,7 @@
     str = inputMamedir->text();
     if (!str.isEmpty())
         config.writeEntry("rompath",inputMamedir->text());
-    config.writeEntry("spooldir",inputSpooldir->text());
+    config.writeEntry("hiscoredir",inputHiscoredir->text());
     QString
         cmd = inputMamecmd->text();
     if (!cmd.isEmpty() && cmd.find("@@Game") < 0) {
@@ -98,8 +98,8 @@
         if (!str.isEmpty())
             prefs->rompath = str;
     }
-    if (config.hasKey("spooldir"))
-        prefs->spooldir = config.readEntry("spooldir");
+    if (config.hasKey("hiscoredir"))
+        prefs->hiscoredir = config.readEntry("hiscoredir");
     if (config.hasKey("mamecmd"))
         prefs->mamecmd = config.readEntry("mamecmd");
     if (config.hasKey("logdir"))
@@ -129,9 +129,9 @@
 	    opt += prefs->rompath;
 	}
     }
-    if (defpref->spooldir != prefs->spooldir) {
-	if (!prefs->spooldir.isEmpty())
-            opt += " -spooldir " + prefs->spooldir;
+    if (defpref->hiscoredir != prefs->hiscoredir) {
+	if (!prefs->hiscoredir.isEmpty())
+            opt += " -hiscore_directory " + prefs->hiscoredir;
     }
     if (defpref->screenshotdir != prefs->screenshotdir) {
 	if (!prefs->screenshotdir.isEmpty())
