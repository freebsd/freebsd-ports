--- xvtext.c.orig	2009-05-20 13:18:36.000000000 +0200
+++ xvtext.c	2009-05-20 13:22:45.000000000 +0200
@@ -181,7 +181,7 @@
 #endif
 #ifdef TV_MULTILINGUAL
 static void setCodingSpec   PARM((TVINFO *, struct coding_spec *));
-static void createCsWins    PARM((char *));
+static void createCsWins    PARM((const char *));
 static void openCsWin       PARM((TVINFO *));
 static void closeCsWin      PARM((TVINFO *));
 #endif
