--- library/tulip/include/tulip/cxx/TemplateFactory.cxx.orig	Sat Nov  9 02:52:54 2002
+++ library/tulip/include/tulip/cxx/TemplateFactory.cxx	Sat Apr 19 23:03:33 2003
@@ -39,7 +39,7 @@
 	else
 	  {
 	    createObj =(func) dlsym(handle, "_creator");
-	    if ((error=dlerror())!=0)
+	    if ((error=(char*)dlerror())!=0)
 	      {
 		dlclose(handle);
 		if (loader!=0) loader->aborted(std::string(namelist[n]->d_name),std::string(error));
