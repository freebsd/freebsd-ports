
$FreeBSD$

--- iodev/soundlnx.cc	2001/05/30 22:19:00	1.1
+++ iodev/soundlnx.cc	2001/05/30 22:19:34
@@ -22,7 +22,7 @@
 
 // This file (SOUNDLNX.CC) written and donated by Josef Drexler
 
-#if defined(linux)
+#if (defined(linux) || defined(__FreeBSD__))
 
 #include "bochs.h"
 
