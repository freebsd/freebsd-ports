
$FreeBSD$

--- extensions/gtkmoz_browser_element/browser_element.cc.orig
+++ extensions/gtkmoz_browser_element/browser_element.cc
@@ -164,7 +164,7 @@
       std::string up_fd_str = StringPrintf("%d", up_fds[1]);
       for (size_t i = 0; kBrowserChildNames[i]; ++i) {
         execl(kBrowserChildNames[i], kBrowserChildNames[i],
-              down_fd_str.c_str(), up_fd_str.c_str(), NULL);
+              down_fd_str.c_str(), up_fd_str.c_str(), (char*)0);
       }
       LOG("Failed to execute browser child");
       _exit(-1);
