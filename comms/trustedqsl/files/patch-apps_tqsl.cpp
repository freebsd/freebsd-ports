--- apps/tqsl.cpp	2014-05-08 17:59:25.000000000 -0700
+++ ../../work.fixed/tqsl-2.0.2/apps/tqsl.cpp	2014-05-24 00:30:44.000000000 -0700
@@ -54,7 +54,7 @@
 #endif
 #include <zlib.h>
 #include <openssl/opensslv.h> // only for version info!
-#include <db.h> //only for version info!
+#include <db5/db.h> //only for version info!
 
 #include <iostream>
 #include <fstream>
