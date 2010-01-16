--- ./our_orde.c.orig	1989-04-04 12:36:22.000000000 -0400
+++ ./our_orde.c	2010-01-16 12:50:32.076328932 -0500
@@ -21,10 +21,11 @@
 static HEADER orders_base;
 static HEADER *orders_allocp = NULL;	
 
+static HEADER *orders_morecore();
+
 char *our_orders_alloc(nbytes)
         ALLOC nbytes;
 {
-	HEADER *orders_morecore();
 	HEADER *p, *q;
 	ALLOC nunits;
 
@@ -76,7 +77,7 @@
 	cp = malloc(rnu * sizeof(HEADER));
 	if (!cp) {
          printf("\nALLOC FAILED IN OUR_ORDERS_ALLOC\n");
-         exit ();
+         exit(0);
         }
 	up = (HEADER *)cp;
 	up->s.size = rnu;
