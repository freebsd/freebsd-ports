--- src/doconfig/doconfig.c.orig	Tue Sep  7 23:52:37 2004
+++ src/doconfig/doconfig.c	Sun Oct 10 11:31:04 2004
@@ -80,12 +80,17 @@
 #endif
 
 int
-main(void)
+main(int argc, char **argv)
 {
     char buf[256];
     char *cp;
     char *pathname;
 
+    if (argc != 2) {
+        printf("Bad usage");
+        exit(-1);
+    }
+
     if ((pathname = safe_getcwd()) == NULL) {
 	printf("Can't get current path!\n");
 	exit(-1);
@@ -101,30 +106,16 @@
     cp = strrchr(pathname, '\\');
     *cp = '\0';
 #endif
-    printf("Configuring...\n");
-    wrmakesrc(pathname);
-    sprintf(buf, "%s/include/gamesdef.h", pathname);
-    wrgamesdef(buf);
-    sprintf(buf, "%s/src/client/ipglob.c", pathname);
-    wripglob(buf);
-
-    if (access(EP, 0)) {
-	printf("making directory %s\n", EP);
-	if (mkdir(EP, 0755)) {
-	    printf("mkdir failed on %s, exiting.\n", EP);
-	    exit(-1);
-	}
-    }
-    sprintf(buf, "%s/data", EP);
-    if (access(buf, 0)) {
-	printf("making directory %s\n", buf);
-	if (mkdir(buf, 0755)) {
-	    printf("mkdir failed on %s, exiting.\n", buf);
-	    exit(-1);
-	}
+    if (!strcasecmp(argv[1], "config")) {
+       printf("Configuring...\n");
+       wrmakesrc(pathname);
+       sprintf(buf, "%s/include/gamesdef.h", pathname);
+       wrgamesdef(buf);
+       sprintf(buf, "%s/src/client/ipglob.c", pathname);
+       wripglob(buf);
+       sprintf(buf, "%s/data/auth", pathname);
+       wrauth(buf);
     }
-    sprintf(buf, "%s/data/auth", EP);
-    wrauth(buf);
     exit(0);
 }
 
