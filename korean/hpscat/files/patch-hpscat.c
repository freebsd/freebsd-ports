--- hpscat.c.orig	1995-11-23 07:46:12.000000000 -0500
+++ hpscat.c	2013-06-12 17:10:59.000000000 -0400
@@ -12,13 +12,14 @@
 bool cheat;
 FILE *fp, *ofp;
 
+static int open_outfile(char *);
+
 /****************
    main routine
  ****************/
 
-main(ac,av)
-  int  ac;
-  char *av[];
+int
+main(int ac, char *av[])
 {
     int  i;
     extern void showfile PROT((char *));
@@ -53,13 +54,13 @@
     exit(0);
 }
 
-int
-open_outfile(s)    /*  returns -1 if can't write */
-  char *s;
+static int
+open_outfile(char *s)    /*  returns -1 if can't write */
 {
     char ans[80], buf[256];
     sprintf(buf,"%s.ps", s);
-    if(ofp=fopen(buf,"r")) { /* file exists */
+    ofp=fopen(buf,"r");
+    if(ofp) { /* file exists */
 	fclose(ofp);
 	fprintf(stderr,"output file %s exists...overwrite? ", buf);
 	gets(ans);
