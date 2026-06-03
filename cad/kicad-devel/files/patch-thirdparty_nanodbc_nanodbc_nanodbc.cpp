--- thirdparty/nanodbc/nanodbc/nanodbc.cpp.orig	2025-08-13 00:57:26 UTC
+++ thirdparty/nanodbc/nanodbc/nanodbc.cpp
@@ -386,10 +386,19 @@ constexpr std::size_t size(const T (&array)[N]) noexce
 }
 #endif
 
+inline std::size_t length(NANODBC_SQLCHAR const* s)
+{
+  std::size_t len = 0;
+  for (; *s != 0; ++s)
+    ++len;
+  return len;
+  
+}
+
 template <std::size_t N>
 inline std::size_t size(NANODBC_SQLCHAR const (&array)[N]) noexcept
 {
-    auto const n = std::char_traits<NANODBC_SQLCHAR>::length(array);
+    auto const n = length(array);
     NANODBC_ASSERT(n < N);
     return n < N ? n : N - 1;
 }
@@ -3720,9 +3729,9 @@ std::list<datasource> list_datasources()
                 "incompatible SQLCHAR and string::value_type");
 
             datasource dsn;
-            dsn.name = string(&name[0], &name[std::char_traits<NANODBC_SQLCHAR>::length(name)]);
+            dsn.name = string(&name[0], &name[length(name)]);
             dsn.driver =
-                string(&driver[0], &driver[std::char_traits<NANODBC_SQLCHAR>::length(driver)]);
+                string(&driver[0], &driver[length(driver)]);
 
             dsns.push_back(std::move(dsn));
             direction = SQL_FETCH_NEXT;
@@ -3773,7 +3782,7 @@ std::list<driver> list_drivers()
                 "incompatible SQLCHAR and string::value_type");
 
             driver drv;
-            drv.name = string(&descr[0], &descr[std::char_traits<NANODBC_SQLCHAR>::length(descr)]);
+            drv.name = string(&descr[0], &descr[length(descr)]);
 
             // Split "Key1=Value1\0Key2=Value2\0\0" into list of key-value pairs
             auto beg = &attrs[0];
