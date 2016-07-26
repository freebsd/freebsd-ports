--- arcrun.c.orig	2010-08-07 13:06:42 UTC
+++ arcrun.c
@@ -98,7 +98,7 @@ runfile(hdr, num, arg)		/* run a file */
 		strcpy(sys, buf);
 
 	else {
-		if (warn) {
+		if (arcwarn) {
 			printf("File %s is not a .BAS, .BAT, .COM, or .EXE\n",
 			       hdr->name);
 			nerrs++;
@@ -112,7 +112,7 @@ runfile(hdr, num, arg)		/* run a file */
               && strcmp(i, ".TTP")
               && strcmp(i, ".TOS"))
       {
-              if (warn) {
+              if (arcwarn) {
                       printf("File %s is not a .PRG, .TOS, or .TTP\n",
                               hdr->name);
                       nerrs++;
@@ -122,7 +122,7 @@ runfile(hdr, num, arg)		/* run a file */
       }
 #endif
 
-	if (warn)
+	if (arcwarn)
 		if ((tmp = fopen(buf, "r")))
 			arcdie("Temporary file %s already exists", buf);
 	if (!(tmp = tmpopen(buf)))
@@ -146,7 +146,7 @@ runfile(hdr, num, arg)		/* run a file */
 	if (system(buf))		/* try to invoke it */
 		arcdie("Execution failed for %s", buf);
 #endif
-	if (unlink(buf) && warn) {
+	if (unlink(buf) && arcwarn) {
 		printf("Cannot unsave temporary file %s\n", buf);
 		nerrs++;
 	}
