--- driver/desc.c.orig	2014-06-19 02:50:16.000000000 +0400
+++ driver/desc.c	2015-03-26 12:34:50.610931661 +0300
@@ -63,13 +63,21 @@
      but in desc_get_rec we manually get a pointer to it. This avoids
      having to call set_dynamic after modifying the DESCREC.
   */
+#ifdef MARIADB_BASE_VERSION
+  if (my_init_dynamic_array(&desc->records, sizeof(DESCREC), 0, 0, 0))
+#else
   if (my_init_dynamic_array(&desc->records, sizeof(DESCREC), 0, 0))
+#endif
   {
     x_free((char *)desc);
     return NULL;
   }
 
+#ifdef MARIADB_BASE_VERSION
+  if (my_init_dynamic_array(&desc->bookmark, sizeof(DESCREC), 0, 0, 0))
+#else
   if (my_init_dynamic_array(&desc->bookmark, sizeof(DESCREC), 0, 0))
+#endif
   {
     delete_dynamic(&desc->records);
     x_free((char *)desc);
@@ -997,7 +1005,12 @@
   delete_dynamic(&dest->records);
   if (my_init_dynamic_array(&dest->records, sizeof(DESCREC),
                             src->records.max_element,
+#ifdef MARIADB_BASE_VERSION
+                            src->records.alloc_increment,
+                            0))
+#else
                             src->records.alloc_increment))
+#endif
   {
     return set_desc_error(dest, "HY001",
               "Memory allocation error",
