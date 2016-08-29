--- regutil/inifile.c.orig	2014-10-25 01:36:33 UTC
+++ regutil/inifile.c
@@ -31,6 +31,7 @@
 #include <ctype.h>
 
 #include "inifile.h"
+#include </usr/include/strings.h>
 
 typedef struct value_T {
    struct value_T * N;
@@ -197,7 +198,7 @@ static int read_ini_raw(inif_t fit)
    fseek(fit->fp, 0, SEEK_SET);
 
    while ((oldoff = ftell(fit->fp)),
-          fgets(buf, sizeof(buf), fit->fp) != NULL) {
+          fgets((char *) buf, sizeof(buf), fit->fp) != NULL) {
 
       /* skip leading whitespace */
       for (i = 0; !pt[buf[i]]; i++)
@@ -207,8 +208,8 @@ static int read_ini_raw(inif_t fit)
        * line */
       switch (pt[buf[i]]) {
          /* errors */
-         case CV_RBRACK: n = "closing bracket"; goto oops;
-         case CV_EQUALS: n = "equals sign"; goto oops;
+         case CV_RBRACK: n = (unsigned char *) "closing bracket"; goto oops;
+         case CV_EQUALS: n = (unsigned char *) "equals sign"; goto oops;
 
          oops:
             fprintf(stderr, "oops: line starts with %s: %s\n", n, buf);
@@ -287,7 +288,7 @@ static int read_ini_raw(inif_t fit)
           *            write anything before the first section */
          case CV_EOS:
          case CV_COMMENT:
-            i = strlen(buf);
+            i = strlen((char *) buf);
             if (lvt) {
                lvt->comment = realloc(lvt->comment, cl + i + 1);
                memcpy(lvt->comment+cl, buf, i+1);
