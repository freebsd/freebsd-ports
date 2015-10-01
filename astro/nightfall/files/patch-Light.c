--- Light.c.orig	2014-09-25 08:03:26 UTC
+++ Light.c
@@ -252,8 +252,10 @@ int main(int argc, char *argv[])
 
   /* >>>>>>>>>>>>>>>>    ALLOCATE MEMORY        <<<<<<<<<<<<<<<<<<<<<  */
 
+#if 0
   program_invocation_name = malloc (1 + strlen(argv[0]));
   strcpy(program_invocation_name, argv[0]);
+#endif
 
   /* should be freed by OS on program exit (?)                         */
 
