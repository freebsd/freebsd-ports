--- kclangctest.c.orig	2012-05-24 11:32:00 UTC
+++ kclangctest.c
@@ -91,7 +91,7 @@ int main(int argc, char **argv) {
 
 
 /* print the usage and exit */
-static void usage() {
+static void usage(void) {
   eprintf("%s: test cases of the C binding of Kyoto Cabinet\n", g_progname);
   eprintf("\n");
   eprintf("usage:\n");
