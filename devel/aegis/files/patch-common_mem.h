--- common/mem.h.orig	2012-12-04 02:03:33 UTC
+++ common/mem.h
@@ -123,7 +123,7 @@ char *dmem_copy_string(const char *file,
 #endif
 
 #if HAVE_HEADER_NEW || HAVE_NEW_H
-#define THROW_BAD_ALLOC throw(std::bad_alloc)
+#define THROW_BAD_ALLOC //throw(std::bad_alloc)
 #else
 #define THROW_BAD_ALLOC
 #endif
