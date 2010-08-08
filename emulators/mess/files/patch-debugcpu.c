--- src/emu/debug/debugcpu.c.orig	2010-08-01 23:31:06.000000000 +0200
+++ src/emu/debug/debugcpu.c	2010-08-01 23:31:23.000000000 +0200
@@ -49,7 +49,9 @@
 #include "debugint/debugint.h"
 #include "uiinput.h"
 #include <ctype.h>
-
+#ifdef __FreeBSD__
+#undef tolower
+#endif
 
 
 /***************************************************************************
