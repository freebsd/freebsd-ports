- Fix compilation with unsigned char SQLCHAR type

--- nanodbc/nanodbc.cpp.orig	2023-01-13 22:42:27 UTC
+++ nanodbc/nanodbc.cpp
@@ -257,10 +257,20 @@ constexpr std::size_t size(const T (&array)[N]) noexc
 }
 #endif
 
+// Helper function to compute string length for SQLCHAR types
+template <typename T>
+inline std::size_t sqlchar_length(const T* str) noexcept
+{
+    const T* s = str;
+    while (*s) ++s;
+    return s - str;
+}
+
 template <std::size_t N>
 inline std::size_t size(NANODBC_SQLCHAR const (&array)[N]) noexcept
 {
-    auto const n = std::char_traits<NANODBC_SQLCHAR>::length(array);
+    // Use custom length function instead of char_traits which doesn't support unsigned char
+    auto const n = sqlchar_length(array);
     NANODBC_ASSERT(n < N);
     return n < N ? n : N - 1;
 }
@@ -3563,9 +3573,9 @@ std::list<datasource> list_datasources()
                 "incompatible SQLCHAR and string::value_type");
 
             datasource dsn;
-            dsn.name = string(&name[0], &name[std::char_traits<NANODBC_SQLCHAR>::length(name)]);
+            dsn.name = string(&name[0], &name[sqlchar_length(name)]);
             dsn.driver =
-                string(&driver[0], &driver[std::char_traits<NANODBC_SQLCHAR>::length(driver)]);
+                string(&driver[0], &driver[sqlchar_length(driver)]);
 
             dsns.push_back(std::move(dsn));
             direction = SQL_FETCH_NEXT;
@@ -3616,7 +3626,7 @@ std::list<driver> list_drivers()
                 "incompatible SQLCHAR and string::value_type");
 
             driver drv;
-            drv.name = string(&descr[0], &descr[std::char_traits<NANODBC_SQLCHAR>::length(descr)]);
+            drv.name = string(&descr[0], &descr[sqlchar_length(descr)]);
 
             drvs.push_back(std::move(drv));
             direction = SQL_FETCH_NEXT;
