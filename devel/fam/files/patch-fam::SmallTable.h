--- fam/SmallTable.h.orig	Tue Jul 16 14:23:25 2002
+++ fam/SmallTable.h	Sat Jul 31 13:14:09 2004
@@ -98,7 +98,7 @@
 }
 
 template <class Tkey, class Tvalue>
-SmallTable<Tkey, Tvalue>::Closure
+typename SmallTable<Tkey, Tvalue>::Closure
 SmallTable<Tkey, Tvalue>::position(const Tkey& key) const
 {
     unsigned l = 0, r = n;
