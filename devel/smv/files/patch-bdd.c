--- bdd.c
+++ bdd.c
@@ -113,7 +113,7 @@
    /* Initialize a keytable. */
    kp->n = n;
    kp->elements_in_table = 0;
-   kp->hash_table_buf = (bdd_ptr *)malloc(n*sizeof(bdd_ptr));
+   kp->hash_table_buf = (bdd_ptr *)smv_malloc(n*sizeof(bdd_ptr));
 
    {  /* Initialize hash bin list pointers to NULL. */
       register int i;
@@ -139,7 +139,7 @@
    /* Create key tables. */
    create_keytable(&reduce_table, KEYTABLESIZE);
    apply_cache_size = APPLY_CACHE_SIZE;
-   apply_cache = (apply_rec *)malloc(sizeof(apply_rec)*apply_cache_size);
+   apply_cache = (apply_rec *)smv_malloc(sizeof(apply_rec)*apply_cache_size);
    {
      int i;
      for(i=0;i<apply_cache_size;i++)apply_cache[i].op = 0;
@@ -1446,7 +1446,7 @@
 }
 
 /* An "infinity" constant - big enough power of 2 not to care about */
-#define INFINITY 1000
+#define SMV_INFINITY 1000
 
 /* similar to auxcount_bdd, but computes log2 of the fraction */
 
@@ -1457,18 +1457,18 @@
   union {float a; bdd_ptr b;} temp;     /* very dangerous!!! */
   double l,r;
 
-  if(d==ZERO)return(-INFINITY); /* = log(0) */
+  if(d==ZERO)return(-SMV_INFINITY); /* = log(0) */
   if(d==ONE)return(0.0);        /* = log2(1) */
   temp.b = find_apply(COUNT_OP,d,ZERO);
   if(temp.b==NULL) {
     l = auxcount_bdd_log2(d->left,n);
     r = auxcount_bdd_log2(d->right,n);
     if(l < r) {
-      if(r - l > INFINITY) temp.a = r;
+      if(r - l > SMV_INFINITY) temp.a = r;
       else temp.a = l - 1.0 + log2(1.0 + pow(2.0,r-l));
     }
     else {
-      if(l - r > INFINITY) temp.a = l;
+      if(l - r > SMV_INFINITY) temp.a = l;
       else temp.a = r - 1.0 + log2(1.0 + pow(2.0,l-r));
     }
   }
