--- src/emu/debug/debugcpu.c.orig	2010-07-30 10:55:52.000000000 +0200
+++ src/emu/debug/debugcpu.c	2010-07-30 10:56:13.000000000 +0200
@@ -49,7 +49,9 @@
 #include "debugint/debugint.h"
 #include "uiinput.h"
 #include <ctype.h>
-
+#ifdef __FreeBSD__
+#undef tolower
+#endif
 
 
 /***************************************************************************
