--- string.c
+++ string.c
@@ -35,7 +35,7 @@
   string_rec a,*res;
   a.text = x;
   if(res = (string_ptr)find_hash(string_hash,&a))return(res);
-  a.text = (char *)strcpy((char *)malloc(strlen(x)+1),x);
+  a.text = (char *)strcpy((char *)smv_malloc(strlen(x)+1),x);
   return((string_ptr)insert_hash(string_hash,&a));
 }
