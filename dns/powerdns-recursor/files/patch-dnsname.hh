--- dnsname.hh.orig	2019-01-31 19:43:44 UTC
+++ dnsname.hh
@@ -30,7 +30,7 @@
 #include <boost/version.hpp>
 
 // it crashes on OSX and doesn't compile on OpenBSD
-#if BOOST_VERSION >= 105300 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 105300 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
 #include <boost/container/string.hpp>
 #endif
 
@@ -135,7 +135,7 @@ class DNSName (public)
   inline bool canonCompare(const DNSName& rhs) const;
   bool slowCanonCompare(const DNSName& rhs) const;  
 
-#if BOOST_VERSION >= 105300 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 105300 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
   typedef boost::container::string string_t;
 #else
   typedef std::string string_t;
