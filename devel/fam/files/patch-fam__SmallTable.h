--- ./fam/SmallTable.h.orig	2003-04-15 06:21:43.000000000 +0200
+++ ./fam/SmallTable.h	2014-01-03 02:35:10.000000000 +0100
@@ -98,7 +98,7 @@
 }
 
 template <class Tkey, class Tvalue>
-SmallTable<Tkey, Tvalue>::Closure
+typename SmallTable<Tkey, Tvalue>::Closure
 SmallTable<Tkey, Tvalue>::position(const Tkey& key) const
 {
     unsigned l = 0, r = n;
