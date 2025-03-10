--- compiler/errors/exception.hh.orig	2025-01-10 00:10:01 UTC
+++ compiler/errors/exception.hh
@@ -25,8 +25,11 @@ Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, U
 #include <stdexcept>
 #ifndef WIN32
 #include <unistd.h>
+#  if !defined(__FreeBSD__)
 #include <alloca.h>
-#else
+#  else
+#include <stdlib.h>
+#  endif
 // #include <io.h>
 #endif
 
