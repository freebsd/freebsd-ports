--- kmamerun/prefgeneraldata.cpp.orig	Wed Feb 26 21:05:23 2003
+++ kmamerun/prefgeneraldata.cpp	Wed Feb 26 21:05:35 2003
@@ -21,14 +21,14 @@
   inputMamedir->setGeometry(120,10,300,30);
   inputMamedir->setMinimumSize(0,0);
 
-  labelSpooldir= new QLabel(this,"NoName");
-  labelSpooldir->setGeometry(10,40,110,30);
-  labelSpooldir->setMinimumSize(0,0);
-  labelSpooldir->setText(i18n("Hiscore directory:"));
+  labelHiscoredir= new QLabel(this,"NoName");
+  labelHiscoredir->setGeometry(10,40,110,30);
+  labelHiscoredir->setMinimumSize(0,0);
+  labelHiscoredir->setText(i18n("Hiscore directory:"));
 
-  inputSpooldir= new QLineEdit(this,"NoName");
-  inputSpooldir->setGeometry(120,40,300,30);
-  inputSpooldir->setMinimumSize(0,0);
+  inputHiscoredir= new QLineEdit(this,"NoName");
+  inputHiscoredir->setGeometry(120,40,300,30);
+  inputHiscoredir->setMinimumSize(0,0);
 
   labelMamecmd= new QLabel(this,"NoName");
   labelMamecmd->setGeometry(10,70,110,30);
