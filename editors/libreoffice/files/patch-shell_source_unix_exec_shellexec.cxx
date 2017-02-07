--- shell/source/unix/exec/shellexec.cxx.orig	2017-01-12 00:54:33 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -157,7 +157,7 @@ void SAL_CALL ShellExec::execute( const 
         if (std::getenv("LIBO_FLATPAK") != nullptr) {
             aBuffer.append("/app/bin/xdg-open");
         } else {
-            aBuffer.append("/usr/bin/xdg-open");
+            aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
         }
 #endif
         aBuffer.append(" ");
