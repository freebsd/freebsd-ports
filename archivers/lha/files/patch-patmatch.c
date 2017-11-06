--- src/patmatch.c.orig	2000-10-04 14:57:38 UTC
+++ src/patmatch.c
@@ -20,7 +20,7 @@ patmatch(p, s, f)
 {
 	char            pc;	/* a single character from pattern */
 
-	while (pc = ((f && islower(*p)) ? toupper(*p++) : *p++)) {
+	while ((pc = ((f && islower(*p)) ? toupper(*p++) : *p++))) {
 		if (pc == '*') {
 			do {	/* look for match till s exhausted */
 				if (patmatch(p, s, f))
