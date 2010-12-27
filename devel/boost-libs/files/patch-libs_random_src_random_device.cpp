--- libs/random/src/random_device.cpp.orig	2010-09-21 16:25:12.000000000 +0200
+++ libs/random/src/random_device.cpp	2010-09-21 16:25:58.000000000 +0200
@@ -17,7 +17,7 @@
 #include <cassert>
 
 
-#if defined(BOOST_NO_INCLASS_MEMBER_INITIALIZATION) && !BOOST_WORKAROUND(BOOST_MSVC, BOOST_TESTED_AT(1600))
+#if !defined(BOOST_NO_INCLASS_MEMBER_INITIALIZATION) && !BOOST_WORKAROUND(BOOST_MSVC, BOOST_TESTED_AT(1600))
 //  A definition is required even for integral static constants
 const bool boost::random_device::has_fixed_range;
 const boost::random_device::result_type boost::random_device::min_value;
