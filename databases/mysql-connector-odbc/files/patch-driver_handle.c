--- driver/handle.c.orig	2014-06-19 02:50:16.000000000 +0400
+++ driver/handle.c	2015-03-26 12:36:14.548929818 +0300
@@ -403,7 +403,11 @@
     }
   }
 
+#ifdef MARIADB_BASE_VERSION
+  my_init_dynamic_array(*param_bind, sizeof(MYSQL_BIND), elements, 10, 0);
+#else
   my_init_dynamic_array(*param_bind, sizeof(MYSQL_BIND), elements, 10);
+#endif
   memset((*param_bind)->buffer, 0, sizeof(MYSQL_BIND) *
 											(*param_bind)->max_element);
 
