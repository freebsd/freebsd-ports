Index: src/dynarr.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/dynarr.c,v
retrieving revision 1.13
retrieving revision 1.14
diff -u -r1.13 -r1.14
--- src/dynarr.c	2005/11/25 01:41:59	1.13
+++ src/dynarr.c	2006/01/20 17:59:50	1.14
@@ -129,16 +129,17 @@
 static int Dynarr_min_size = 8;
 
 static void
-Dynarr_realloc (Dynarr *dy, Bytecount new_size)
+Dynarr_realloc (Dynarr *dy, int new_size)
 {
   if (DUMPEDP (dy->base))
     {
       void *new_base = malloc (new_size);
-      memcpy (new_base, dy->base, dy->max > new_size ? dy->max : new_size);
+      memcpy (new_base, dy->base, 
+	      (dy->max < new_size ? dy->max : new_size) * dy->elsize);
       dy->base = new_base;
     }
   else
-    dy->base = xrealloc (dy->base, new_size);
+    dy->base = xrealloc (dy->base, new_size * dy->elsize);
 }
 
 void *
@@ -158,13 +159,13 @@
 			       Dynarr);
 
 static void
-Dynarr_lisp_realloc (Dynarr *dy, Elemcount new_size)
+Dynarr_lisp_realloc (Dynarr *dy, int new_size)
 {
   void *new_base = alloc_lrecord_array (dy->elsize, new_size, dy->lisp_imp);
   void *old_base = dy->base;
   if (dy->base)
     memcpy (new_base, dy->base, 
-	    (dy->max > new_size ? dy->max : new_size) * dy->elsize);
+	    (dy->max < new_size ? dy->max : new_size) * dy->elsize);
   dy->base = new_base;
   if (old_base)
     mc_free (old_base);
@@ -205,9 +206,9 @@
       if (dy->lisp_imp)
 	Dynarr_lisp_realloc (dy, newsize);
       else
-	Dynarr_realloc (dy, newsize*dy->elsize);
+	Dynarr_realloc (dy, newsize);
 #else /* not NEW_GC */
-      Dynarr_realloc (dy, newsize*dy->elsize);
+      Dynarr_realloc (dy, newsize);
 #endif /* not NEW_GC */
       dy->max = newsize;
     }
