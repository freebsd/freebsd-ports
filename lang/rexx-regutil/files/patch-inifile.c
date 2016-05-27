--- inifile.c.orig	2003-02-20 00:04:42 UTC
+++ inifile.c
@@ -194,7 +194,7 @@ static int read_ini_raw(inif_t fit)
    fseek(fit->fp, 0, SEEK_SET);
 
    while ((oldoff = ftell(fit->fp)), 
-          fgets(buf, sizeof(buf), fit->fp) != NULL) {
+          fgets((char *) buf, sizeof(buf), fit->fp) != NULL) {
 
       /* skip leading whitespace */
       for (i = 0; !pt[buf[i]]; i++)
@@ -204,8 +204,8 @@ static int read_ini_raw(inif_t fit)
        * line */
       switch (pt[buf[i]]) {
          /* errors */
-         case CV_RBRACK: n = "closing bracket"; goto oops;
-         case CV_EQUALS: n = "equals sign"; goto oops;
+         case CV_RBRACK: n = (unsigned char *) "closing bracket"; goto oops;
+         case CV_EQUALS: n = (unsigned char *) "equals sign"; goto oops;
 
          oops:
             fprintf(stderr, "oops: line starts with %s: %s\n", n, buf);
@@ -284,7 +284,7 @@ static int read_ini_raw(inif_t fit)
           *            write anything before the first section */
          case CV_EOS:
          case CV_COMMENT:
-            i = strlen(buf);
+            i = strlen((char *) buf);
             if (lvt) {
                lvt->comment = realloc(lvt->comment, cl + i + 1);
                memcpy(lvt->comment+cl, buf, i+1);
