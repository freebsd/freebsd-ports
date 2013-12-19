--- src/im/account.cpp.orig
+++ src/im/account.cpp
@@ -18,6 +18,7 @@
 
 #include <cassert>
 #include <cstring>
+#include <unistd.h>
 #ifdef HAVE_IMLIB
 	#include <Imlib2.h>
 #endif /* HAVE_IMLIB */
