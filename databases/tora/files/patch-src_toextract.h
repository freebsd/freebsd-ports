--- src/toextract.h	2010-02-02 13:25:43.000000000 -0500
+++ src/toextract.h	2015-03-08 20:14:45.000000000 -0400
@@ -783,5 +783,5 @@
         /** Implement sort order based only on Order field.
          */
-        bool operator <(const columnInfo &inf)
+        bool operator <(const columnInfo &inf) const
         {
             return Order < inf.Order;
@@ -789,5 +789,5 @@
         /** Implement sort order based only on Order field.
          */
-        bool operator ==(const columnInfo &inf)
+        bool operator ==(const columnInfo &inf) const
         {
             return Order == inf.Order;
