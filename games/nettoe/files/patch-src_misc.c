--- src/misc.c.orig	2014-03-21 08:46:52 UTC
+++ src/misc.c
@@ -44,6 +44,10 @@
 #include "misc.h"
 #include "terminal.h"
 
+int NO_BEEP;
+int NO_COLORS;
+int addrfamily;
+
 int who_start_first(void)
 {
 	long generated_number;
