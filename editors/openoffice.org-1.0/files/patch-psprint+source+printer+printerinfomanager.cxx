--- psprint/source/printer/printerinfomanager.cxx.orig	Sat Apr  6 11:56:35 2002
+++ psprint/source/printer/printerinfomanager.cxx	Wed May  1 22:42:58 2002
@@ -883,7 +883,7 @@
 
 static const struct SystemCommandParameters aParms[] =
 {
-#if defined(LINUX) || defined(NETBSD)
+#if defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
     { "/usr/sbin/lpc status", "lpr -P (PRINTER)", "", ":", 0 },
     { "lpc status", "lpr -P (PRINTER)", "", ":", 0 },
     { "LANG=C;LC_ALL=C;export LANG LC_ALL;lpstat -s", "lp -d (PRINTER)", "system for ", ": ", 1 }
