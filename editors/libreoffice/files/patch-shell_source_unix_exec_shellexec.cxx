--- shell/source/unix/exec/shellexec.cxx.orig	2020-11-22 14:05:28 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -168,7 +168,7 @@ void SAL_CALL ShellExec::execute( const OUString& aCom
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("/usr/local/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
