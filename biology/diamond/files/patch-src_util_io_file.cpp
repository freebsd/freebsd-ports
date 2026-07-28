--- src/util/io/file.cpp.orig	2026-07-13 11:36:09 UTC
+++ src/util/io/file.cpp
@@ -21,6 +21,8 @@ along with this program.  If not, see <http://www.gnu.
 #ifdef _WIN32
 #include <io.h>
 #include <fcntl.h>
+#else
+#include <unistd.h> // unlink
 #endif
 #include <string.h> // strerror
 #include "file.h"
