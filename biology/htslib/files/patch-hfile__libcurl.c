--- hfile_libcurl.c.orig	2015-12-15 16:34:33 UTC
+++ hfile_libcurl.c
@@ -39,6 +39,10 @@ DEALINGS IN THE SOFTWARE.  */
 
 #include <curl/curl.h>
 
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
+
 typedef struct {
     hFILE base;
     CURL *easy;
