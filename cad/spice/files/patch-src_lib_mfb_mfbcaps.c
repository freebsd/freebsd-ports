--- src/lib/mfb/mfbcaps.c.orig	1991-04-01 22:32:50 UTC
+++ src/lib/mfb/mfbcaps.c
@@ -26,6 +26,7 @@ Author: -C- 1982 Giles Billingsley
 #include "spice.h"
 #include "mfb.h"
 #include <ctype.h>
+#include <string.h>
 #include "suffix.h"
 
 
@@ -43,9 +44,9 @@ static int hopcount;       /* detect infinite loops in
 
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
