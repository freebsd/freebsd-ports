--- src/credits/credits.cc.orig	Fri Jun 11 14:25:40 1999
+++ src/credits/credits.cc	Sun Jan 25 23:14:42 2004
@@ -72,50 +72,50 @@
         int erase_title;
 } _ci[] = {
 {"PROGRAMMING",
-"THOMAS
-NYBERG", 0},
+"THOMAS"
+"NYBERG", 0},
 {"PROGRAMMING",
-"  JONAS
-BORGSTROM", 1},
+"  JONAS"
+"BORGSTROM", 1},
 {"GRAPHICS",
-"  DICK
-ADOLFSSON", 1},
+"  DICK"
+"ADOLFSSON", 1},
 {"DESIGN",
-" PETTER
-HOLMBERG", 0},
+" PETTER"
+"HOLMBERG", 0},
 {"DESIGN",
-"MARKUS
-BOMAN", 1},
+"MARKUS"
+"BOMAN", 1},
 {"SOUND",
-"  EMIL
-ERIKSSON", 0},
+"  EMIL"
+"ERIKSSON", 0},
 {"SOUND",
-"RICHARD
-BERGMARK", 1},
+"RICHARD"
+"BERGMARK", 1},
 {"MUSIC",
-"SAMUEL
-PERSSON", 1},
+"SAMUEL"
+"PERSSON", 1},
 };
 
 #define NUMCI ((signed)(sizeof(_ci) / sizeof(_ci[0])))
 
 char *special_thanks =
-"
- SPECIAL THANKS
-
- PER JONNY KACK
-  TOR SANDEN
-MARKUS WILLANDER
-    UFFEMAN
-    HASSEMAN
-  ANNA NORBERG
-
-    DESCENT
-
- AND OURSELVES
-
-      NOW
-  PLAY URBAN";
+""
+" SPECIAL THANKS"
+""
+" PER JONNY KACK"
+"  TOR SANDEN"
+"MARKUS WILLANDER"
+"    UFFEMAN"
+"    HASSEMAN"
+"  ANNA NORBERG"
+""
+"    DESCENT"
+""
+" AND OURSELVES"
+""
+"      NOW"
+"  PLAY URBAN";
 
 
 uchar lightmap[256 * 256] = {};
