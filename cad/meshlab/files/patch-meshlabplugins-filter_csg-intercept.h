--- meshlabplugins/filter_csg/intercept.h.orig	2015-01-25 21:48:25.000000000 +0100
+++ meshlabplugins/filter_csg/intercept.h	2015-01-25 21:49:09.000000000 +0100
@@ -7,8 +7,13 @@
     #include <unordered_map>
     #include <unordered_set>
 #else
+#   if !defined(_LIBCPP_VERSION)
     #include <tr1/unordered_map>
     #include <tr1/unordered_set>
+#   else
+    #include <unordered_map>
+    #include <unordered_set>
+#   endif
 #endif
 
 #include <vcg/complex/complex.h>
@@ -29,7 +34,7 @@
 //MSVC++ 7.0  _MSC_VER = 1300
 //MSVC++ 6.0  _MSC_VER = 1200
 //MSVC++ 5.0  _MSC_VER = 1100
-#if defined(_MSC_VER) && (_MSC_VER > 1500)
+#if (defined(_MSC_VER) && (_MSC_VER > 1500)) || defined(_LIBCPP_VERSION)
 #else
 	 namespace tr1 {
 #endif
@@ -38,11 +43,15 @@
         {
             std::size_t operator()(const vcg::Point3i &x) const
             {
+#if !defined(_LIBCPP_VERSION)
                 std::tr1::hash<int> h;
+#else
+                std::hash<int> h;
+#endif
                 return ((x[0]) * 131 + h(x[1])) * 131 + h(x[2]);
             }
         };
-#if defined(_MSC_VER) && (_MSC_VER > 1500)
+#if (defined(_MSC_VER) && (_MSC_VER > 1500)) || defined(_LIBCPP_VERSION)
 #else
 	 }
 #endif       
@@ -823,9 +832,15 @@
         {
             typedef typename MeshType::VertexPointer VertexPointer;
             typedef typename MeshType::CoordType CoordType;
+#if !defined(_LIBCPP_VERSION)
             typedef typename std::tr1::unordered_map<const InterceptType*,size_t> VertexTable;
             typedef typename std::tr1::unordered_map<vcg::Point3i,float> SamplesTable;
             typedef typename std::tr1::unordered_set<vcg::Point3i> CellsSet;
+#else
+            typedef typename std::unordered_map<const InterceptType*,size_t> VertexTable;
+            typedef typename std::unordered_map<vcg::Point3i,float> SamplesTable;
+            typedef typename std::unordered_set<vcg::Point3i> CellsSet;
+#endif
 
             void clear() {
                 _vertices.clear();
