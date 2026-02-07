--- dia2code/main.c.orig	2020-08-28 18:45:26 UTC
+++ dia2code/main.c
@@ -72,6 +72,7 @@ char *outdir = NULL;   /* Output directory */
 
 int INDENT_CNT = 4; /* This should be a parameter in the command line */
 int bOpenBraceOnNewline = 1; /* This should also be a command-line parameter */
+int generate_backup;
 
 int main(int argc, char **argv) {
     int i;
