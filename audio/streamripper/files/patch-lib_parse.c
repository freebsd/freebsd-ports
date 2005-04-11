--- lib/parse.c.orig
+++ lib/parse.c
@@ -68,14 +68,14 @@
 	PARSERULE_ICASE,
 	0, 0, 0, 0,
 	0, 
-	"[[:space:]]*-?[[:space:]]*mp3pro$",
+	" *-? *mp3pro$",
 	""
     },
     { PARSERULE_CMD_MATCH, 
 	PARSERULE_ICASE,
 	1, 2, 0, 0,
-	0, 
-	"^[[:space:]]*([^-]*?)[[:space:]]*-[[:space:]]*(.*?)[[:space:]]*$",
+	0,
+	"^ *([^-]*)? *- *(.*) *$", 
 	""
     },
     { 0x00, 
