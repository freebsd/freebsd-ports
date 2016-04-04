--- dnsname.cc.orig	2016-03-18 18:34:07 UTC
+++ dnsname.cc
@@ -142,8 +142,8 @@ bool DNSName::isPartOf(const DNSName& pa
     return false;
 
   // this is slightly complicated since we can't start from the end, since we can't see where a label begins/ends then
-  for(auto us=d_storage.cbegin(); us<d_storage.cend() && std::distance(us,d_storage.cend()) >= static_cast<unsigned int>(parent.d_storage.size()); us+=*us+1) {
-    if (std::distance(us,d_storage.cend()) == static_cast<unsigned int>(parent.d_storage.size())) {
+  for(auto us=d_storage.cbegin(); us<d_storage.cend() && std::distance(us,d_storage.cend()) >= static_cast<int>(parent.d_storage.size()); us+=*us+1) {
+    if (std::distance(us,d_storage.cend()) == static_cast<int>(parent.d_storage.size())) {
       auto p = parent.d_storage.cbegin();
       for(; us != d_storage.cend(); ++us, ++p) {
         if(dns2_tolower(*p) != dns2_tolower(*us))
