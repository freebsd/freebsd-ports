--- eboxy/pluginmanager.cpp.orig	Sat Sep 28 20:41:36 2002
+++ eboxy/pluginmanager.cpp	Tue Oct  8 04:19:13 2002
@@ -79,7 +79,7 @@
   }
   else {
     // Load failed
-    char *errorstr = dlerror();
+    const char *errorstr = dlerror();
     cerr << "Couldn't load plugin " << libfile << endl;
     cerr << errorstr << endl;
     delete plugin;
