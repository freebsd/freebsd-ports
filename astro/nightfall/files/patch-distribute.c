--- distribute.c.orig	2012-01-25 13:36:01 UTC
+++ distribute.c
@@ -36,11 +36,11 @@ static char * build_cmdline(int full)
 {
   int    i;
   char   temp[512];
-  size_t size    = strlen(program_invocation_name) + 1;
+  size_t size    = strlen(g_get_prgname()) + 1;
   size_t len;
   char * cmdline = malloc(size);
   
-  strncpy(cmdline, program_invocation_name, size);
+  strncpy(cmdline, g_get_prgname(), size);
   
   if (full)
     {
