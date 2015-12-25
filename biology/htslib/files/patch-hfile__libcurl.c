--- hfile_libcurl.c.orig	2015-12-22 22:35:42 UTC
+++ hfile_libcurl.c
@@ -39,6 +39,11 @@ DEALINGS IN THE SOFTWARE.  */
 
 #include <curl/curl.h>
 
+#include <sys/param.h>
+#if defined(__FreeBSD__) && (__FreeBSD_version < 1000033) && !defined(ENOTRECOVERABLE)
+#	define ENOTRECOVERABLE EIO
+#endif
+
 typedef struct {
     hFILE base;
     CURL *easy;
