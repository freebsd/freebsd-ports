--- library/tulip/include/tulip/cxx/TemplateFactory.cxx.orig	Wed Apr  2 23:46:09 2003
+++ library/tulip/include/tulip/cxx/TemplateFactory.cxx	Mon May 26 14:31:29 2003
@@ -13,7 +13,7 @@
 #include <dirent.h>
 
 //implemented in TlpTools.cpp
-int __tulip_selectSO(const struct dirent *ent);
+int __tulip_selectSO(struct dirent *ent);
 
 template<class ObjectFactory, class ObjectType, class Parameter>
 bool TemplateFactory<ObjectFactory, ObjectType, Parameter>::exists(const std::string &pluginName) {
@@ -43,7 +43,7 @@
       }
       else {
 	createObj =(func) dlsym(handle, "_creator");
-	if ((error=dlerror())!=0) {
+	if ((error=(char*)dlerror())!=0) {
 	  dlclose(handle);
 	  if (loader!=0) loader->aborted(std::string(namelist[n]->d_name),std::string(error));
 	}
