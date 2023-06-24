--- src/mongo/util/net/ssl_types.h.orig	2023-06-15 22:07:57 UTC
+++ src/mongo/util/net/ssl_types.h
@@ -61,6 +61,7 @@ class SSLX509Name { (public)
         auto equalityLens() const {
             return std::tie(oid, type, value);
         }
+        friend bool operator==(const Entry& lhs, const Entry& rhs);
     };
 
     SSLX509Name() = default;
