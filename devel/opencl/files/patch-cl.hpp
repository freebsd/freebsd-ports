--- cl.hpp.orig	2013-09-01 13:35:56.642641000 +0000
+++ cl.hpp
@@ -210,11 +210,10 @@
 #include <string>
 #endif 
 
-#if defined(linux) || defined(__APPLE__) || defined(__MACOSX)
+#if defined(linux) || defined(__APPLE__) || defined(__MACOSX) \
+ || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <alloca.h>
 
-#include <emmintrin.h>
-#include <xmmintrin.h>
 #endif // linux
 
 #include <cstring>
@@ -1037,7 +1036,7 @@ namespace detail {
 #endif // !_WIN32
     }
 
-    inline void fence() { _mm_mfence(); }
+    inline void fence() { __sync_synchronize(); }
 }; // namespace detail
 
     
@@ -2037,6 +2036,26 @@ public:
 #endif // #if defined(CL_VERSION_1_1)
 };
 
+template <typename Func>
+cl_int detail::GetInfoHelper<Func, VECTOR_CLASS<cl::Device> >::
+    get(Func f, cl_uint name, VECTOR_CLASS<cl::Device>* param)
+    {
+        ::size_t required;
+        cl_int err = f(name, 0, NULL, &required);
+        if (err != CL_SUCCESS) {
+            return err;
+        }
+
+        cl_device_id* value = (cl_device_id*) alloca(required);
+        err = f(name, required, value, NULL);
+        if (err != CL_SUCCESS) {
+            return err;
+        }
+
+        param->assign(&value[0], &value[required/sizeof(cl_device_id)]);
+        return CL_SUCCESS;
+    }
+
 /*! \brief Class interface for cl_platform_id.
  *
  *  \note Copies of these objects are inexpensive, since they don't 'own'
