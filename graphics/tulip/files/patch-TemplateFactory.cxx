--- library/include/cxx/TemplateFactory.cxx.orig	Fri Jan 10 12:29:37 2003
+++ library/include/cxx/TemplateFactory.cxx	Fri Jan 10 12:30:17 2003
@@ -41,7 +41,7 @@
 	else
 	  {
 	    createObj =(func) dlsym(handle, "_creator");
-	    if ((error=dlerror())!=0)
+	    if ((error=(char*)dlerror())!=0)
 	      {
 		dlclose(handle);
 		if (loader!=0) loader->aborted(std::string(namelist[n]->d_name),std::string(error));
