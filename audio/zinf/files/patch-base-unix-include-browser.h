--- base/unix/include/browser.h.orig	Sun Dec 15 10:34:14 2002
+++ base/unix/include/browser.h	Sat Jan 18 04:33:14 2003
@@ -8,6 +8,8 @@
 #define BROWSER_H
 #include <string>
 
+using namespace std;
+
 typedef enum
 {
    eBrowserNetscape = 0,
