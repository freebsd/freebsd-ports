--- plugin/icedteanp/IcedTeaPluginUtils.cc.orig	2016-02-03 13:47:43 UTC
+++ plugin/icedteanp/IcedTeaPluginUtils.cc
@@ -1017,7 +1017,7 @@ NPString IcedTeaPluginUtilities::NPStringCopy(const st
     char* utf8 = (char*)browser_functions.memalloc(result.size() + 1);
     strncpy(utf8, result.c_str(), result.size() + 1);
 
-    NPString npstr = {utf8, result.size()};
+    NPString npstr = {utf8, (uint32_t)result.size()};
     return npstr;
 }
 
