--- src/svnfrontend/importdir_logmsg.cpp.orig	Fri Apr 28 15:15:33 2006
+++ src/svnfrontend/importdir_logmsg.cpp	Fri Apr 28 15:16:21 2006
@@ -43,7 +43,7 @@
 
 void Importdir_logmsg::createDirboxDir(const QString & which)
 {
-    m_createDirBox->setText(i18n("Create subdir %1 on import").arg(which.isEmpty()?"(Last part)":which));
+    m_createDirBox->setText(i18n("Create subdir %1 on import").arg(which.isEmpty()?i18n("(Last part)"):which));
 }
 
 #include "importdir_logmsg.moc"
