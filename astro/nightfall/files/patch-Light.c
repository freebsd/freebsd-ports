--- Light.c.orig	2016-08-26 08:14:53 UTC
+++ Light.c
@@ -254,8 +254,10 @@ int main(int argc, char *argv[])
 
   /* >>>>>>>>>>>>>>>>    ALLOCATE MEMORY        <<<<<<<<<<<<<<<<<<<<<  */
 
+#if 0
   program_invocation_name = malloc (1 + strlen(argv[0]));
   strcpy(program_invocation_name, argv[0]);
+#endif
 
   /* should be freed by OS on program exit (?)                         */
 
