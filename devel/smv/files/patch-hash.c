--- hash.c
+++ hash.c
@@ -7,12 +7,12 @@
 int (*hash_fun)(),(*eq_fun)();
 mgr_ptr mgr;
 {
-  hash_ptr res = (hash_ptr)malloc(sizeof(struct hash));
+  hash_ptr res = (hash_ptr)smv_malloc(sizeof(struct hash));
   res->size = init_size;
   res->hash_fun = hash_fun;
   res->eq_fun = eq_fun;
   res->mgr = mgr;
-  res->tab = (rec_ptr *)malloc(init_size * sizeof(rec_ptr));
+  res->tab = (rec_ptr *)smv_malloc(init_size * sizeof(rec_ptr));
   bzero(res->tab,init_size * sizeof(rec_ptr));
   return(res);
 }
