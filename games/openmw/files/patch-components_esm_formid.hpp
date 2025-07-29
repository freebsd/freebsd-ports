--- components/esm/formid.hpp.orig	2025-07-01 11:41:15 UTC
+++ components/esm/formid.hpp
@@ -51,10 +51,10 @@ namespace std
     {
         size_t operator()(const ESM::FormId& formId) const
         {
-            static_assert(sizeof(ESM::FormId) == sizeof(size_t));
-            size_t s;
-            memcpy(&s, &formId, sizeof(size_t));
-            return hash<size_t>()(s);
+            static_assert(sizeof(ESM::FormId) == sizeof(uint64_t));
+            uint64_t s;
+            memcpy(&s, &formId, sizeof(ESM::FormId));
+            return hash<uint64_t>()(s);
         }
     };
 
