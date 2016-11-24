https://github.com/PowerDNS/pdns/issues/2955

--- dnsname.hh.orig	2016-09-06 12:50:29 UTC
+++ dnsname.hh
@@ -30,7 +30,7 @@
 #include <boost/version.hpp>
 
 // it crashes on OSX and doesn't compile on OpenBSD
-#if BOOST_VERSION >= 104800 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 104800 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
 #include <boost/container/string.hpp>
 #endif
 
@@ -133,7 +133,7 @@ public:
   inline bool canonCompare(const DNSName& rhs) const;
   bool slowCanonCompare(const DNSName& rhs) const;  
 
-#if BOOST_VERSION >= 104800 && ! defined( __APPLE__ ) && ! defined(__OpenBSD__)
+#if BOOST_VERSION >= 104800 && ! defined(_LIBCPP_VERSION) && ! defined(__OpenBSD__)
   typedef boost::container::string string_t;
 #else
   typedef std::string string_t;
