--- arcrun.c.orig	2013-06-27 02:00:19 UTC
+++ arcrun.c
@@ -96,7 +96,7 @@ runfile(hdr, num, arg)		/* run a file */
 		strcpy(sys, buf);
 
 	else {
-		if (warn) {
+		if (arcwarn) {
 			printf("File %s is not a .BAS, .BAT, .COM, or .EXE\n",
 			       hdr->name);
 			nerrs++;
@@ -110,7 +110,7 @@ runfile(hdr, num, arg)		/* run a file */
               && strcmp(i, ".TTP")
               && strcmp(i, ".TOS"))
       {
-              if (warn) {
+              if (arcwarn) {
                       printf("File %s is not a .PRG, .TOS, or .TTP\n",
                               hdr->name);
                       nerrs++;
@@ -120,7 +120,7 @@ runfile(hdr, num, arg)		/* run a file */
       }
 #endif
 
-	if (warn)
+	if (arcwarn)
 		if ((tmp = fopen(buf, "r")))
 			arcdie("Temporary file %s already exists", buf);
 	if (!(tmp = tmpopen(buf)))
@@ -144,7 +144,7 @@ runfile(hdr, num, arg)		/* run a file */
 	if (system(buf))		/* try to invoke it */
 		arcdie("Execution failed for %s", buf);
 #endif
-	if (unlink(buf) && warn) {
+	if (unlink(buf) && arcwarn) {
 		printf("Cannot unsave temporary file %s\n", buf);
 		nerrs++;
 	}
