--- lua-recursor4.cc.orig	2016-09-06 12:50:29 UTC
+++ lua-recursor4.cc
@@ -263,8 +263,8 @@ RecursorLua4::RecursorLua4(const std::st
       return DNSName(boost::get<const DNSName>(dom));
   });
   d_lw->registerFunction("isPartOf", &DNSName::isPartOf);
-  d_lw->registerFunction("countLabels", &DNSName::countLabels);
-  d_lw->registerFunction("wirelength", &DNSName::wirelength);
+  d_lw->registerFunction<unsigned int(DNSName::*)()>("countLabels", [](const DNSName& name) { return name.countLabels(); });
+  d_lw->registerFunction<size_t(DNSName::*)()>("wirelength", [](const DNSName& name) { return name.wirelength(); });
   d_lw->registerFunction<bool(DNSName::*)(const std::string&)>(
     "equal",
      [](const DNSName& lhs, const std::string& rhs) {
@@ -285,9 +285,9 @@ RecursorLua4::RecursorLua4(const std::st
     } );
   d_lw->registerFunction<bool(ComboAddress::*)()>("isIPv4", [](const ComboAddress& ca) { return ca.sin4.sin_family == AF_INET; });
   d_lw->registerFunction<bool(ComboAddress::*)()>("isIPv6", [](const ComboAddress& ca) { return ca.sin4.sin_family == AF_INET6; });
-  d_lw->registerFunction("isMappedIPv4", &ComboAddress::isMappedIPv4);
-  d_lw->registerFunction("mapToIPv4", &ComboAddress::mapToIPv4);
-  d_lw->registerFunction("truncate", &ComboAddress::truncate);
+  d_lw->registerFunction<bool(ComboAddress::*)()>("isMappedIPv4", [](const ComboAddress& ca) { return ca.isMappedIPv4(); });
+  d_lw->registerFunction<ComboAddress(ComboAddress::*)()>("mapToIPv4", [](const ComboAddress& ca) { return ca.mapToIPv4(); });
+  d_lw->registerFunction<void(ComboAddress::*)(unsigned int)>("truncate", [](ComboAddress& ca, unsigned int bits) { ca.truncate(bits); });
 
   d_lw->writeFunction("newCA", [](const std::string& a) { return ComboAddress(a); });
   typedef std::unordered_set<ComboAddress,ComboAddress::addressOnlyHash,ComboAddress::addressOnlyEqual> cas_t;
