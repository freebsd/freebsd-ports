--- Sources/Core/IOData/Unix/directory_scanner_unix.cpp.orig	Thu Jan 10 11:23:30 2002
+++ Sources/Core/IOData/Unix/directory_scanner_unix.cpp	Sat Jan 24 13:31:49 2004
@@ -13,6 +13,7 @@
         ------------------------------------------------------------------------
 */
 
+#include <assert.h>
 #include <API/Core/System/error.h>
 #include <iostream>
 #include <libgen.h>
