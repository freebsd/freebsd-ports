--- Light.c.orig	Thu Oct 20 22:54:11 2005
+++ Light.c	Wed Dec  7 02:43:38 2005
@@ -275,8 +275,10 @@
 
   /* >>>>>>>>>>>>>>>>    ALLOCATE MEMORY        <<<<<<<<<<<<<<<<<<<<<  */
 
+#if 0
   program_invocation_name = malloc (1 + strlen(argv[0]));
   strcpy(program_invocation_name, argv[0]);
+#endif
 
   /* should be freed by OS on program exit (?)                         */
 
