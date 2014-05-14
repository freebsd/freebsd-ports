--- boost/multi_array/base.hpp.orig	2012-05-17 10:52:48.000000000 -0400
+++ boost/multi_array/base.hpp	2014-05-06 17:14:55.000000000 -0400
@@ -65,7 +65,7 @@
 // object creation in small-memory environments.  Thus, the objects
 // can be left undefined by defining BOOST_MULTI_ARRAY_NO_GENERATORS 
 // before loading multi_array.hpp.
-#if !BOOST_MULTI_ARRAY_NO_GENERATORS
+#ifndef BOOST_MULTI_ARRAY_NO_GENERATORS
 namespace {
   multi_array_types::extent_gen extents;
   multi_array_types::index_gen indices;
