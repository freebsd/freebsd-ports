--- src/third_party/asio-master/asio/include/asio/detail/config.hpp.orig	2023-04-29 10:17:24 UTC
+++ src/third_party/asio-master/asio/include/asio/detail/config.hpp
@@ -19,6 +19,7 @@
 // individual scons objects.
 # define ASIO_STANDALONE // MongoDB
 # define ASIO_SEPARATE_COMPILATION // MongoDB
+# define ASIO_HAS_STD_INVOKE_RESULT // FreeBSD
 
 #if defined(ASIO_STANDALONE)
 # define ASIO_DISABLE_BOOST_ARRAY 1
