
$FreeBSD$

--- src/wp/ap/unix/ap_UnixApp.cpp	2001/11/23 15:08:40	1.1
+++ src/wp/ap/unix/ap_UnixApp.cpp	2001/11/23 15:11:10
@@ -606,7 +606,7 @@
 
       UT_DEBUGMSG(("DOM: leading plugins from %s\n", pluginDir.c_str()));
       
-      n = scandir(pluginDir.c_str(), &namelist, so_only, alphasort);
+      n = scandir(pluginDir.c_str(), &namelist, (int (*)(dirent *))so_only, alphasort);
       if (n < 0)
 	{
 	  UT_DEBUGMSG(("DOM: no plugins found\n"));
