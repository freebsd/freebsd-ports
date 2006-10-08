--- perpetrate.c.orig	Sun Mar  9 03:24:35 2003
+++ perpetrate.c	Mon Oct  9 01:56:53 2006
@@ -125,7 +125,7 @@
     tuple	*tp;
     atom	*op;
     int		c, i;
-    char	*includedir, *libdir, *getenv();
+    char	*includedir, *libdir, *loclibdir, *getenv();
     FILE	*ifp, *ofp;
     int		maxabstain, nextcount, bugline;
     bool        needsyslib, firstfile;
@@ -136,6 +136,8 @@
       libdir = ICKLIBDIR;
     if (!(compiler = getenv("CC")))
       compiler = CC;
+    
+    loclibdir = "/usr/local/lib";
 
     while ((c = getopt(argc, argv, "bcdtOC@")) != EOF)
     {
@@ -498,8 +500,8 @@
 	    if (!compile_only)
 	    {
 		(void) sprintf(buf2,
-			       "%s %s -I%s -L%s -lick -o %s",
-			       compiler, buf, includedir, libdir,
+			       "%s %s -I%s -L%s -L%s -lick -o %s",
+			       compiler, buf, includedir, libdir, loclibdir,
 			       argv[optind]);
 		(void) system(buf2);
 		(void) unlink(buf);
