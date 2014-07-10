--- host/lib/usrp/dboard_id.cpp.orig	2014-04-01 21:48:39.542370984 -0400
+++ host/lib/usrp/dboard_id.cpp	2014-04-01 21:50:22.617363414 -0400
@@ -51,9 +51,11 @@
 
 dboard_id_t dboard_id_t::from_string(const std::string &string){
     if (string.substr(0, 2) == "0x"){
-        return dboard_id_t::from_uint16(boost::lexical_cast<to_hex<boost::uint16_t> >(string));
+      std::stringstream interpreter(string);
+      to_hex<boost::uint16_t> hh;
+      interpreter >>hh;
+      return dboard_id_t::from_uint16(hh);
     }
-    return dboard_id_t::from_uint16(boost::lexical_cast<boost::uint16_t>(string));
 }
 
 std::string dboard_id_t::to_string(void) const{
