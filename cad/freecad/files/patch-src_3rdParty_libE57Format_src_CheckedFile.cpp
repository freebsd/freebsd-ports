--- src/3rdParty/libE57Format/src/CheckedFile.cpp.orig	2024-03-20 18:17:18 UTC
+++ src/3rdParty/libE57Format/src/CheckedFile.cpp
@@ -25,6 +25,11 @@
  * DEALINGS IN THE SOFTWARE.
  */
 
+// convenience for all the BSDs
+#if defined( __FreeBSD__) || defined( __NetBSD__) || defined( __OpenBSD__)
+#define __BSD
+#endif
+
 #if defined( _WIN32 )
 #if defined( _MSC_VER )
 #include <codecvt>
@@ -47,6 +52,10 @@
 #elif defined( __APPLE__ )
 #include <sys/types.h>
 #include <unistd.h>
+#elif defined( __BSD )
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <unistd.h>
 #else
 #error "no supported OS platform defined"
 #endif
@@ -483,7 +492,7 @@ uint64_t CheckedFile::lseek64( int64_t offset, int whe
 #endif
 #elif defined( __linux__ )
    int64_t result = ::lseek64( fd_, offset, whence );
-#elif defined( __APPLE__ )
+#elif defined( __APPLE__ ) || defined ( __BSD )
    int64_t result = ::lseek( fd_, offset, whence );
 #else
 #error "no supported OS platform defined"
