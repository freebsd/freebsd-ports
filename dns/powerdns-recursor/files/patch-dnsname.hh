--- dnsname.hh.orig	2020-05-08 09:31:59 UTC
+++ dnsname.hh
@@ -33,7 +33,7 @@
 #include <boost/version.hpp>
 
 // it crashes on OSX and doesn't compile on OpenBSD
-#if BOOST_VERSION >= 105300 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 105300 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
 #include <boost/container/string.hpp>
 #endif
 
@@ -138,7 +138,7 @@ class DNSName (public)
   inline bool canonCompare(const DNSName& rhs) const;
   bool slowCanonCompare(const DNSName& rhs) const;  
 
-#if BOOST_VERSION >= 105300 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 105300 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
   typedef boost::container::string string_t;
 #else
   typedef std::string string_t;
