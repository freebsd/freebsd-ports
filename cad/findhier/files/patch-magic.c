--- magic.c.orig	Sun Apr 29 00:53:23 2007
+++ magic.c	Sun Apr 29 00:53:59 2007
@@ -16,7 +16,7 @@
 #ifdef _UNIX_
 #include <pwd.h>
 uid_t getuid();
-#endif _UNIX_
+#endif /* _UNIX_ */
 
 #define ENVIRON ".magic"
 
@@ -84,7 +84,7 @@
 	while((tmp=getpath(env))!=NULL) add_path(tmp);
 	(void)fclose(env);
 }
-#endif _UNIX_
+#endif /* _UNIX_ */
 
 void myenviron()
 {
@@ -92,7 +92,7 @@
 	char buf[BUFSIZE];
 	struct passwd *cad;
 	uid_t uid;
-#endif _UNIX_
+#endif /* _UNIX_ */
 
 	add_path(".");
 #ifdef _UNIX_
@@ -110,7 +110,7 @@
 	proc(ENVIRON);
 
 	path_reversal();
-#endif _UNIX_
+#endif /* _UNIX_ */
 }
 
 /* magic.c */
