--- ../../vcglib/vcg/complex/algorithms/subset.h.orig	2013-10-31 09:34:59.000000000 +0100
+++ ../../vcglib/vcg/complex/algorithms/subset.h	2013-10-31 09:35:06.000000000 +0100
@@ -86,12 +86,12 @@
     return (v<o.v);
   }
   
-  bool operator ==(const InsertedV & o)
+  bool operator ==(const InsertedV & o) const
   {
     return (v==o.v);
   }
   
-  bool operator !=(const InsertedV & o)
+  bool operator !=(const InsertedV & o) const
   {
     return (v!=o.v);
   }
