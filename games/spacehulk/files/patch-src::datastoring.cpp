--- src/datastoring.cpp.orig	Mon Jul  7 14:36:01 2003
+++ src/datastoring.cpp	Mon Jul  7 14:36:49 2003
@@ -272,8 +272,8 @@
     infos.smtp = getPref("smtp");
     infos.yourEmail = getPref("email");
     infos.opponentEmail = man->email;
-    infos.port = getPref("smtpPort").isEmpty()? "25" : getPref("smtpPort");
-    infos.login = getPref("smtpLogin");
+    infos.port=getPref("smtpPort").isEmpty() ? QString("25") :
+    getPref("smtpPort");
     infos.password = getPref("smtpPassword");
     man->guicmd->GetSmtpInfos(&infos);
     addPref("smtp",infos.smtp);
