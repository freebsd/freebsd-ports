--- ../CGAL-5.6.1/include/CGAL/boost/graph/iterator.h	2024-02-24 21:04:12 UTC
+++ ../CGAL-5.6.1/include/CGAL/boost/graph/iterator.h
@@ -214,11 +214,6 @@ class Halfedge_around_source_iterator { (public)
 
 #ifndef DOXYGEN_RUNNING
 
-  explicit operator bool() const
-  {
-    return (! (this->base() == nullptr));
-  }
-
   bool operator==( const Self& i) const {
     CGAL_assertion( anchor == anchor);
     return  ( g == i.g) && ( pos == i.pos) && ( winding == i.winding);
@@ -308,11 +303,6 @@ class Halfedge_around_target_iterator { (public)
 
 #ifndef DOXYGEN_RUNNING
 
-  explicit operator bool() const
-  {
-    return (! (this->base() == nullptr));
-  }
-
   bool operator==( const Self& i) const {
     CGAL_assertion( anchor == anchor);
     return  ( g == i.g) && ( pos == i.pos) && ( winding == i.winding);
@@ -399,11 +389,6 @@ class Halfedge_around_face_iterator { (public)
   const value_type& operator *  ( ) const { return  pos; }
   pointer           operator -> ( )       { return &pos; }
   const value_type* operator -> ( ) const { return &pos; }
-
-  explicit operator bool() const
-  {
-    return (! (this->base() == nullptr));
-  }
 
   bool operator==( const Self& i) const {
     CGAL_assertion( anchor == anchor);
