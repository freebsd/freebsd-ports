--- ../psprint/source/printer/printerinfomanager.cxx.orig	Sat Mar  2 22:16:34 2002
+++ ../psprint/source/printer/printerinfomanager.cxx	Sat Mar  2 22:16:12 2002
@@ -883,7 +883,7 @@
 
 static const struct SystemCommandParameters aParms[] =
 {
-#ifdef LINUX
+#ifdef LINUX || defined(FREEBSD) || defined(NETBSD)
     { "/usr/sbin/lpc status", "lpr -P (PRINTER)", "", ":", 0 },
     { "lpc status", "lpr -P (PRINTER)", "", ":", 0 },
     { "LANG=C;LC_ALL=C;export LANG LC_ALL;lpstat -s", "lp -d (PRINTER)", "system for ", ": ", 1 }
