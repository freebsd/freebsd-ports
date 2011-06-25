--- src/lib/mfb/mfbcaps.c.orig	1991-04-01 22:32:50.000000000 +0000
+++ src/lib/mfb/mfbcaps.c	2011-06-24 19:53:27.000000000 +0000
@@ -26,6 +26,7 @@
 #include "spice.h"
 #include "mfb.h"
 #include <ctype.h>
+#include <string.h>
 #include "suffix.h"
 
 
@@ -43,9 +44,9 @@
 
 FILE   *POpen();
 char   *strcpy();
-char   *MFBSkip();
+static char   *MFBSkip();
 char   *MFBGetStr();
-char   *MFBCapDecod();
+static char   *MFBCapDecod();
 int    MFBGetNum();
 int    MFBGetFlag();
 int    MFBGetEnt();
