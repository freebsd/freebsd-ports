--- shell/source/unix/exec/shellexec.cxx.orig	2017-12-08 02:26:19.000000000 +0300
+++ shell/source/unix/exec/shellexec.cxx	2017-12-12 15:51:21.551684000 +0300
@@ -145,7 +145,7 @@
         aBuffer.append("open --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
