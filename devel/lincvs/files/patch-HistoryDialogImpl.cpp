--- src/HistoryDialogImpl.cpp.orig	Fri Aug 20 10:48:34 2004
+++ src/HistoryDialogImpl.cpp	Fri Aug 20 10:56:13 2004
@@ -268,7 +268,8 @@
   if (failed) return;
   switch( cmd) {
      case EDIT_REVISION_CMD: {
-	 setPermission(QFile(tmpViewFileName),READABLE);//don't think you could change the file
+	 QFile tmpFile(tmpViewFileName);
+	 setPermission(tmpFile, READABLE);//don't think you could change the file
 	 emit editFile(tmpViewFileName);
 	 break;
      }
