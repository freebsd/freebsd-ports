--- libavrdude.h.orig	2017-03-30 13:30:41 UTC
+++ libavrdude.h
@@ -337,6 +337,8 @@ typedef void (*walk_avrparts_cb)(const char *name, con
                                  void *cookie);
 void walk_avrparts(LISTID avrparts, walk_avrparts_cb cb, void *cookie);
 void sort_avrparts(LISTID avrparts);
+uint8_t get_fuse_bitmask(AVRMEM * m);
+int compare_memory_masked(AVRMEM * m, unsigned char buf1, unsigned char buf2);
 #ifdef __cplusplus
 }
 #endif
