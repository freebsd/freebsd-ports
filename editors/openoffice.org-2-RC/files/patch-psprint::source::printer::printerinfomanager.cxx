--- ../psprint/source/printer/printerinfomanager.cxx.orig	Wed Oct 16 00:02:09 2002
+++ ../psprint/source/printer/printerinfomanager.cxx	Fri Oct 18 20:02:54 2002
@@ -883,7 +883,7 @@
 
 static const struct SystemCommandParameters aParms[] =
 {
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
     { "/usr/sbin/lpc status", "lpr -P \"(PRINTER)\"", "", ":", 0 },
     { "lpc status", "lpr -P \"(PRINTER)\"", "", ":", 0 },
     { "LANG=C;LC_ALL=C;export LANG LC_ALL;lpstat -s", "lp -d \"(PRINTER)\"", "system for ", ": ", 1 }
