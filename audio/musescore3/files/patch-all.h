--- all.h.orig	2021-02-06 15:14:17 UTC
+++ all.h
@@ -34,12 +34,12 @@
    #define _HAS_AUTO_PTR_ETC 1
 #endif
 
-#include <stdio.h>
-#include <limits.h>
+#include <cstdio>
+#include <climits>
 #include <map>
 #include <set>
 #include <deque>
-#include <errno.h>
+#include <cerrno>
 #include <fcntl.h>
 // VStudio does not have <unistd.h>, <io.h> & <process.h> replace many functions from it...
 #if (defined (_MSCVER) || defined (_MSC_VER))
@@ -48,7 +48,7 @@
 #else
    #include <unistd.h>
 #endif
-#include <math.h>
+#include <cmath>
 #include <array>
 #include <functional>
 #include <memory>
