--- cpp.orig/include/IceUtil/Config.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/IceUtil/Config.h	2012-09-10 11:43:58.000000000 +0200
@@ -248,3 +248,16 @@ public:
 #define ICE_DEFAULT_MUTEX_PROTOCOL PrioNone
 
 #endif
+
+
+//
+// Macro used for declaring destructors that might throw - required for C++11
+//
+#if __cplusplus >= 201103L
+#define ICE_DESTRUCTORS_DONT_THROW_BY_DEFAULT
+#define ICE_NOEXCEPT_FALSE noexcept(false)
+#define ICE_NOEXCEPT_TRUE noexcept(true)
+#else
+#define ICE_NOEXCEPT_FALSE
+#define ICE_NOEXCEPT_TRUE
+#endif
