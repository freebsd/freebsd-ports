
$FreeBSD$

--- iodev/soundlnx.h.orig	Tue Apr 10 05:20:00 2001
+++ iodev/soundlnx.h	Thu May 31 01:07:43 2001
@@ -23,7 +23,7 @@
 // This file (SOUNDLNX.H) written and donated by Josef Drexler
 
 
-#if defined(linux)
+#if (defined(linux) || defined(__FreeBSD__))
 
 #include "bochs.h"
 
