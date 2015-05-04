--- uppsrc/ide/SrcUpdater/Install.cpp.orig	2012-08-31 12:10:00 UTC
+++ uppsrc/ide/SrcUpdater/Install.cpp
@@ -282,7 +282,12 @@ void InstallWizard::Perform(){
 			if(!CopyFolder(UpdaterCfg().localsrc,UpdaterCfg().globalsrc,&p)){
 				Exclamation(DeQtf("Failed to copy "+UpdaterCfg().globalsrc+" to "+UpdaterCfg().localsrc));
 			}
-			DeleteFile(AppendFileName(UpdaterCfg().localsrc,"GCC.bm"));
+			FindFile ff(AppendFileName(UpdaterCfg().globalsrc, "*.bm"));
+			while (ff) {
+				if (ff.IsFile())
+					FileDelete(AppendFileName(UpdaterCfg().localsrc, ff.GetName()));
+				ff.Next();
+			}
 			break;
 		}
 		case 1:{
