--- library/tulip/include/tulip/tulipconf.h.orig	Thu Mar 13 20:20:34 2003
+++ library/tulip/include/tulip/tulipconf.h	Fri Oct 29 14:14:08 2004
@@ -8,7 +8,7 @@
 #else
 #  define STL_EXT_NS __gnu_cxx
 #  define _DEPRECATED __attribute__ ((deprecated))
-#  include <ext/stl_hash_fun.h>
+#  include <ext/hash_fun.h>
 #endif
 
 #include <string>
