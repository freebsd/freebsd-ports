--- ./our_allo.c.orig	1989-04-04 12:36:21.000000000 -0400
+++ ./our_allo.c	2010-01-16 12:50:32.073330216 -0500
@@ -21,10 +21,11 @@
 static HEADER base;
 static HEADER *allocp = NULL;	
 
+static HEADER *morecore();
+
 char *our_alloc(nbytes)
         ALLOC nbytes;
 {
-	HEADER *morecore();
 	HEADER *p;
 	HEADER *q;
 	ALLOC nunits;
@@ -76,7 +77,7 @@
 	cp = malloc(rnu * sizeof(HEADER));
 	if (!cp) {
            printf("\n ERROR: ALLOCATION FAILED IN MORECORE\n");
-           exit();  
+           exit(0);  
         }
 	up = (HEADER *)cp;
 	up->s.size = rnu;
