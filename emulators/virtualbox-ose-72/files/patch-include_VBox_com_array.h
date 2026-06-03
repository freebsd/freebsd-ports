--- include/VBox/com/array.h.orig	2025-08-13 19:37:15 UTC
+++ include/VBox/com/array.h
@@ -181,7 +181,7 @@
 
 #include "VBox/com/defs.h"
 
-#if RT_GNUC_PREREQ(4, 6) || (defined(_MSC_VER) && (_MSC_VER >= 1600))
+#if RT_GNUC_PREREQ(4, 6) || (defined(_MSC_VER) && (_MSC_VER >= 1600)) || defined(_LIBCPP_VERSION)
 /** @def VBOX_WITH_TYPE_TRAITS
  * Type traits are a C++ 11 feature, so not available everywhere (yet).
  * Only GCC 4.6 or newer and MSVC++ 16.0 (Visual Studio 2010) or newer.
@@ -1014,12 +1014,12 @@ class SafeArray : public Traits (public)
     {
         /** @todo r=klaus should do this as a AssertCompile, but cannot find a way which works. */
         Assert(sizeof(T) <= sizeof(Zeroes));
-        AssertReturn(m.arr != NULL, *(T *)&Zeroes[0]);
-        AssertReturn(aIdx < size(), *(T *)&Zeroes[0]);
+        AssertReturn(m.arr != NULL,  *((T *)1));
+        AssertReturn(aIdx < size(), *((T *)1));
 #ifdef VBOX_WITH_XPCOM
         return m.arr[aIdx];
 #else
-        AssertReturn(m.raw != NULL, *(T *)&Zeroes[0]);
+        AssertReturn(m.raw != NULL,  *((T *)1));
         return m.raw[aIdx];
 #endif
     }
@@ -1034,7 +1034,7 @@ class SafeArray : public Traits (public)
 #ifdef VBOX_WITH_XPCOM
         return m.arr[aIdx];
 #else
-        AssertReturn(m.raw != NULL, *(const T *)&Zeroes[0]);
+         AssertReturn(m.raw != NULL,  *((T *)1));
         return m.raw[aIdx];
 #endif
     }
