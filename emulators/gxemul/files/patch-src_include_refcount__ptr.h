--- src/include/refcount_ptr.h.orig	2014-08-17 08:45:13 UTC
+++ src/include/refcount_ptr.h
@@ -33,6 +33,8 @@ template <class T>
 class refcount_ptr;
 
 
+#include <stddef.h>
+
 /**
  * \brief Base class for reference countable objects.
  *
