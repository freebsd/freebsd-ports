--- src/acoroexpected.h.orig	2024-11-11 20:32:28 UTC
+++ src/acoroexpected.h
@@ -3,6 +3,9 @@
 #include <adatabase.h>
 #include <aresult.h>
 #include <asqlexports.h>
+#include <atransaction.h>
+
+#include <concepts>
 #include <coroutine>
 #include <expected>
 
@@ -34,7 +37,7 @@ class ASQL_EXPORT ACoroExpected (public)
 
     std::expected<T, QString> await_resume() { return m_result; }
 
-    ACoroExpected(QObject *receiver)
+    ACoroExpected(QObject *receiver) requires (std::same_as<T, ATransaction>)
         : m_receiver(receiver)
         , m_result{std::unexpected(QString{})}
     {
@@ -42,11 +45,24 @@ class ASQL_EXPORT ACoroExpected (public)
             if (result.error()) {
                 m_result = std::unexpected(result.errorString());
             } else {
-                if constexpr (std::is_same_v<T, ATransaction>) {
-                    m_result = ATransaction(database, true);
-                } else {
-                    m_result = result;
-                }
+                m_result = ATransaction(database, true);
+            }
+
+            if (m_handle) {
+                m_handle.resume();
+            }
+        };
+    }
+
+    ACoroExpected(QObject *receiver) requires (!std::same_as<T, ATransaction>)
+        : m_receiver(receiver)
+        , m_result{std::unexpected(QString{})}
+    {
+        callback = [this](AResult &result) {
+            if (result.error()) {
+                m_result = std::unexpected(result.errorString());
+            } else {
+                m_result = result;
             }
 
             if (m_handle) {
