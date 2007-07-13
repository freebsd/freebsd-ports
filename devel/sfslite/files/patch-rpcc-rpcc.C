--- rpcc/rpcc.C.orig	2005-07-15 23:21:51.000000000 +0000
+++ rpcc/rpcc.C	2007-07-12 22:39:01.000000000 +0000
@@ -152,8 +152,8 @@
   void (*fn) (str) = NULL;
   int len;
 
-  av.push_back (PATH_CPP);
-  av.push_back ("-DRPCC");
+  av.push_back ((char *)PATH_CPP);
+  av.push_back ((char *)"-DRPCC");
   av.push_back (NULL);
 
   for (an = 1; an < argc; an++) {
@@ -213,38 +213,38 @@
 
   switch (mode) {
   case HEADER:
-    av[2] = "-DRPCC_H";
+    av[2] = (char *)"-DRPCC_H";
     fn = genheader;
     if (!outfile)
       outfile = strbuf ("%.*sh", len - 1, basename);
     break;
   case CFILE:
-    av[2] = "-DRPCC_C";
+    av[2] = (char *)"-DRPCC_C";
     fn = gencfile;
     if (!outfile)
       outfile = strbuf ("%.*sC", len - 1, basename);
     break;
   case PYTHON:
-    av[2] = "-DRPCC_P";
+    av[2] = (char *)"-DRPCC_P";
     fn = genpython;
     if (!outfile)
       outfile = strbuf ("%.*spy", len - 1, basename);
      break;
   case PYL:
-    av[2] = "-DRPCC_PYL";
+    av[2] = (char *)"-DRPCC_PYL";
     fn = genpyc_lib;
     // foo.x -> foo_lib.C
     if (!outfile)
       outfile = strbuf ("%.*s_lib.C", len - 2, basename);
     break;
   case PYH:
-    av[2] = "-DRPCC_PYH";
+    av[2] = (char *)"-DRPCC_PYH";
     fn = genpyh;
     if (!outfile)
       outfile = strbuf ("%.*sh", len -1, basename);
     break;
   case PYS:
-    av[2] = "-DRPCC_PYS";
+    av[2] = (char *)"-DRPCC_PYS";
     fn = genpyc_so;
     // foo.x -> foo_so.C
     if (!outfile)
