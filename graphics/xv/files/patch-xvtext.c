--- src/xvtext.c.orig	2023-07-17 01:25:42 UTC
+++ src/xvtext.c
@@ -181,7 +181,7 @@ static int  selectCodeset         PARM((TVINFO *));
 #endif
 #ifdef TV_MULTILINGUAL
 static void setCodingSpec   PARM((TVINFO *, struct coding_spec *));
-static void createCsWins    PARM((char *));
+static void createCsWins    PARM((const char *));
 static void openCsWin       PARM((TVINFO *));
 static void closeCsWin      PARM((TVINFO *));
 #endif
