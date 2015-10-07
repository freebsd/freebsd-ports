--- driver/parse.c.orig	2014-06-19 02:50:16.000000000 +0400
+++ driver/parse.c	2015-03-26 12:37:12.112907082 +0300
@@ -129,8 +129,13 @@
 
     /* TODO: Store offsets rather than ptrs. In this case we will be fine
        if work with copy of the originally parsed string */
+#ifdef MARIADB_BASE_VERSION
+    my_init_dynamic_array(&pq->token,     sizeof(uint), 20, 10, 0);
+    my_init_dynamic_array(&pq->param_pos, sizeof(uint), 10, 10, 0);
+#else
     my_init_dynamic_array(&pq->token,     sizeof(uint), 20, 10);
     my_init_dynamic_array(&pq->param_pos, sizeof(uint), 10, 10);
+#endif
   }
 
   return pq;
