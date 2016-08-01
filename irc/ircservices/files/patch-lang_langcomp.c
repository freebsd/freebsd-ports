--- lang/langcomp.c.orig	2009-07-11 14:53:19 UTC
+++ lang/langcomp.c
@@ -115,7 +115,7 @@ static int stringnum(const char *name)
 /* Read a non-comment, non-blank line from the input file.  Return NULL at
  * end of file. */
 
-static char *getline(FILE *f)
+static char *get_line(FILE *f)
 {
     static char buf[1024];
     char *s;
@@ -196,7 +196,7 @@ int main(int ac, char **av)
         return 1;
     }
 
-    while (maxerr > 0 && (line = getline(in)) != NULL) {
+    while (maxerr > 0 && (line = get_line(in)) != NULL) {
         if (*line == '\t') {
             if (curstring == -2) {
                 fprintf(stderr, "%s:%d: Junk at beginning of file\n",
