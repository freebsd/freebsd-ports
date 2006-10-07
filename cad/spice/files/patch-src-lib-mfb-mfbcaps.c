--- src/lib/mfb/mfbcaps.c.orig	Sat Oct  7 15:56:38 2006
+++ src/lib/mfb/mfbcaps.c	Sat Oct  7 15:57:51 2006
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
