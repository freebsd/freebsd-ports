--- storage.h
+++ storage.h
@@ -12,8 +12,8 @@
 #define ALLOCSIZE (2<<15)
 
 void init_storage();
-char *malloc();
-void free();
+char* smv_malloc();
+void smv_free();
 mgr_ptr new_mgr();
 rec_ptr new_rec(),dup_rec();
 void free_rec();
