--- src/osgPlugins/txp/ORIG/trpage_sys.h	Thu Apr 25 17:31:16 2002
+++ src/osgPlugins/txp/trpage_sys.h	Fri May 24 19:24:39 2002
@@ -58,9 +58,16 @@
 // Delete a file
 #define TRPGDELETEFILE(file) remove((file))
 
+#  if defined(__FreeBSD__)
+#    include <inttypes.h>
+typedef int64_t  int64;
+#  else
+
 #ifndef int64
 typedef long long int64;
 #endif
+
+#  endif
 
 #endif
 
