--- libvisual/lv_mem.h.orig	2014-06-24 19:51:48.637214311 +0100
+++ libvisual/lv_mem.h	2014-06-24 19:53:14.723215426 +0100
@@ -76,9 +76,9 @@
 
 /* prototypes */
 int visual_mem_initialize (void);
-void *visual_mem_malloc (visual_size_t nbytes) __malloc;
-void *visual_mem_malloc0 (visual_size_t nbytes) __malloc;
-void *visual_mem_realloc (void *ptr, visual_size_t nbytes) __malloc;
+void *visual_mem_malloc (visual_size_t nbytes) VIS_ATTR_MALLOC;
+void *visual_mem_malloc0 (visual_size_t nbytes) VIS_ATTR_MALLOC;
+void *visual_mem_realloc (void *ptr, visual_size_t nbytes) VIS_ATTR_MALLOC;
 int visual_mem_free (void *ptr);
 
 /* Optimal performance functions set by visual_mem_initialize(). */
