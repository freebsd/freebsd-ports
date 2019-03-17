--- dnsdist-lua-vars.cc.orig	2018-10-03 09:48:10 UTC
+++ dnsdist-lua-vars.cc
@@ -22,6 +22,8 @@
 #include "dnsdist.hh"
 #include "ednsoptions.hh"
 
+#undef BADSIG // signal.h SIG_ERR
+
 void setupLuaVars()
 {
   g_lua.writeVariable("DNSAction", std::unordered_map<string,int>{
