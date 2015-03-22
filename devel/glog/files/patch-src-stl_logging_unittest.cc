--- src/stl_logging_unittest.cc.orig	2015-03-11 12:02:27.000000000 +0800
+++ src/stl_logging_unittest.cc	2015-03-22 01:03:23.871621079 +0800
@@ -41,6 +41,7 @@
 // C++0x isn't enabled by default in GCC and libc++ does not have
 // non-standard ext/* and tr1/unordered_*.
 # if defined(_LIBCPP_VERSION)
+#  define GLOG_STL_LOGGING_FOR_FORWARD_LIST
 #  define GLOG_STL_LOGGING_FOR_UNORDERED
 # else
 #  define GLOG_STL_LOGGING_FOR_EXT_HASH
