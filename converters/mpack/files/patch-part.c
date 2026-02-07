--- part.c
+++ part.c
@@ -27,6 +27,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include "part.h"
@@ -58,7 +59,7 @@
 /*
  * Close and free 'part'.
  */
-int part_close(struct part *part)
+void part_close(struct part *part)
 {
     fclose(part->infile);
     if (part->buf) free(part->buf);
@@ -77,8 +78,7 @@
 /*
  * Add to 'part' the multipart boundary 'boundary'.
  */
-int
-part_addboundary(struct part *part, char *boundary)
+void part_addboundary(struct part *part, char *boundary)
 {
     /* Grow boundary array if necessary */
     if (part->boundary_num == part->boundary_alloc) {
@@ -165,8 +165,7 @@
  * Leaves room in the input buffer to push back an additional single
  * character using the prot_ungetc() macro.
  */
-int
-part_ungets(char *s, struct part *part)
+void part_ungets(char *s, struct part *part)
 {
     int len = strlen(s);
     int i;
