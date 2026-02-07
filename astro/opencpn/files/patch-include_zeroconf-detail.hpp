--- include/zeroconf-detail.hpp.orig	2020-07-15 18:02:29 UTC
+++ include/zeroconf-detail.hpp
@@ -21,7 +21,7 @@
 #include <winsock2.h>
 #else
     #ifndef __WXOSX__
-        #include <error.h>
+//        #include <error.h>
     #else    
         #include <mach/error.h> 
 #endif
@@ -424,4 +424,4 @@ namespace Zeroconf
     }
 }
 
-#endif // ZEROCONF_DETAIL_HPP
\ No newline at end of file
+#endif // ZEROCONF_DETAIL_HPP
