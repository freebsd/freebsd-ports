--- as.c.orig	Sat May  9 15:13:05 1998
+++ as.c	Fri Dec 11 17:14:47 1998
@@ -2577,6 +2577,13 @@
 
    ParamCount=argc-1; ParamStr=argv;
 
+   if (ParamCount == 0)
+    BEGIN
+       fprintf(stderr, "Usage: %s [ option(s) ] file(s) [ option(s) ] file(s)\n",
+                       argv[0]);
+       exit(0);
+    END
+    
    if (First)
     BEGIN
      endian_init(); nls_init(); bpemu_init(); stdhandl_init();
