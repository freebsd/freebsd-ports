--- netcmp/main.c
+++ netcmp/main.c
@@ -122,16 +122,6 @@
 
   outfyle = NULL;
   while (outfyle == NULL) {
-      char username[100];
-      char *tmp;
-
-#if defined(freebsd)
-      getpwuid(getuid(), username);
-#else
-      getpw(getuid(), username);
-#endif
-      tmp = strchr(username,':');
-      if (tmp != NULL) *tmp = '\0';
       printf("  Enter output file name [info]: ");
       fgets(command, 81, stdin);
       TEMP = strchr(command, '\n');
