--- wftk/region.h.orig	Sat May  7 23:58:28 2005
+++ wftk/region.h	Sun May  8 00:01:36 2005
@@ -166,7 +166,7 @@
   // const_iterator has to be declared after RegionBox
 
   /// Iterator over points in the region
-  friend class const_iterator
+  class const_iterator
   {
    public:
     const_iterator() : box_(0) {}
