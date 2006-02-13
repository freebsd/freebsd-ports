--- lib/parse.c.orig	Sun Sep 11 12:45:28 2005
+++ lib/parse.c	Sun Sep 11 12:45:28 2005
@@ -70,14 +70,14 @@
 	PARSERULE_ICASE,
 	0, 0, 0, 0,
 	0, 
-	"[[:space:]]*-?[[:space:]]*mp3pro$",
+ 	" *-? *mp3pro$",
 	""
     },
     { PARSERULE_CMD_MATCH, 
 	PARSERULE_ICASE,
 	1, 2, 0, 0,
-	0, 
-	"^[[:space:]]*([^-]*[^-[:space:]])[[:space:]]*-[[:space:]]*(.*)[[:space:]]*$",
+ 	0,
+ 	"^ *([^-]*[^- ]) *- *(.*) *$",
 	""
     },
     { 0x00, 
