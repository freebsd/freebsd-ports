--- spice3f5/common/src/lib/mfb/mfbcaps.c.orig	1994-01-29 19:07:32 UTC
+++ spice3f5/common/src/lib/mfb/mfbcaps.c
@@ -43,9 +43,9 @@ static int hopcount;       /* detect inf
 
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
