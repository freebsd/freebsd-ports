
$FreeBSD$

--- extensions/gtkmoz_browser_element/browser_element.cc.orig
+++ extensions/gtkmoz_browser_element/browser_element.cc
@@ -380,7 +380,7 @@
         for (size_t i = 0; kBrowserChildNames[i]; ++i) {
           execl(kBrowserChildNames[i], kBrowserChildNames[i],
                 down_fd_str.c_str(), up_fd_str.c_str(),
-                ret_fd_str.c_str(), NULL);
+                ret_fd_str.c_str(), (char*)0);
         }
         LOG("Failed to execute browser child");
         _exit(-1);
