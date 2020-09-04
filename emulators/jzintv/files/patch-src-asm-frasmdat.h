--- src/asm/frasmdat.h.orig	2010-12-24 04:00:49 UTC
+++ src/asm/frasmdat.h
@@ -146,7 +146,7 @@ extern int  listflag;
 extern int hexvalid, hexflag;
 Global FILE *romoutf, *binoutf, *cfgoutf, *loutf;
 Global char *loutfn;
-Global int listlineno;
+extern int listlineno;
 extern int errorcnt, warncnt;
 
 
