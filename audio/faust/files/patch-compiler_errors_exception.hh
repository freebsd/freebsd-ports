--- compiler/errors/exception.hh.orig	2025-03-11 20:48:17 UTC
+++ compiler/errors/exception.hh
@@ -24,7 +24,11 @@ Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, U
 #include <sstream>
 #include <stdexcept>
 #ifndef WIN32
+#  if !defined(__FreeBSD__)
 #include <alloca.h>
+#  else
+#include <stdlib.h>
+#  endif
 #include <unistd.h>
 #else
 // #include <io.h>
