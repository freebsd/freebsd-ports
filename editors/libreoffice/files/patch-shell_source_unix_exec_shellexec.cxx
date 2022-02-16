--- shell/source/unix/exec/shellexec.cxx.orig	2022-01-26 14:35:29 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -212,7 +212,7 @@ void SAL_CALL ShellExec::execute( const OUString& aCom
     }
 
     OString cmd =
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
         // avoid blocking (call it in background)
         "( " + aBuffer.makeStringAndClear() +  " ) &";
 #else
