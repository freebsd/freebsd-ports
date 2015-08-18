--- src/toextract.h.orig	2010-02-02 18:25:43 UTC
+++ src/toextract.h
@@ -782,13 +782,13 @@ public:
         }
         /** Implement sort order based only on Order field.
          */
-        bool operator <(const columnInfo &inf)
+        bool operator <(const columnInfo &inf) const
         {
             return Order < inf.Order;
         }
         /** Implement sort order based only on Order field.
          */
-        bool operator ==(const columnInfo &inf)
+        bool operator ==(const columnInfo &inf) const
         {
             return Order == inf.Order;
         }
