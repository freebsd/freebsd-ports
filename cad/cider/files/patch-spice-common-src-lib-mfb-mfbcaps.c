--- spice/common/src/lib/mfb/mfbcaps.c.orig	Sun Jan 30 04:07:32 1994
+++ spice/common/src/lib/mfb/mfbcaps.c	Fri Dec 22 21:08:10 2006
@@ -43,9 +43,9 @@
 
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
