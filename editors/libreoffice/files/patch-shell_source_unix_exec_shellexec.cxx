--- shell/source/unix/exec/shellexec.cxx.orig	2022-12-22 00:14:09 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -229,7 +229,7 @@ void SAL_CALL ShellExec::execute( const OUString& aCom
     }
 
     OString cmd =
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
         // avoid blocking (call it in background)
         "( " + aBuffer +  " ) &";
 #else
