--- setup2/source/custom/jvmsetup/jvmdlg.cxx.orig	Sat Jul 20 23:33:50 2002
+++ setup2/source/custom/jvmsetup/jvmdlg.cxx	Sat Jul 20 23:34:00 2002
@@ -154,7 +154,7 @@
 
 #if defined (OS2)
 	maHelpEdit.SetText( ResId(STR_HELP_TEXT_OS2, pResMgr) );
-#elif defined (LINUX)
+#elif defined (LINUX) || defined (FREEBSD) || defined (NETBSD)
 	maHelpEdit.SetText( ResId(STR_HELP_TEXT_LINUX, pResMgr) );
 #elif defined (SOLARIS)
 	maHelpEdit.SetText( ResId(STR_HELP_TEXT_SOLARIS, pResMgr) );
