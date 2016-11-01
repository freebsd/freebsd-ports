--- src/base/fs_unix.h.orig	2016-09-23 15:59:20 UTC
+++ src/base/fs_unix.h
@@ -13,6 +13,8 @@
 #include <cstdio>               // Required for rename()
 #include <cstdlib>
 #include <ctime>
+#include <cstdio>
+#include <climits>
 #include <stdexcept>
 #include <vector>
 
