--- src/osdep.h.orig	2003-04-20 18:34:47 UTC
+++ src/osdep.h
@@ -32,6 +32,14 @@
 extern "C"
 {
 #include <netdb.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#ifdef BSD
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netdb.h>
+#endif
 
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
@@ -63,10 +71,27 @@ namespace aprsd
                                       char *buf, size_t buflen, struct hostent **result,
                                       int *h_errnop)
     {
-#ifdef __GLIBC__
+#ifdef BSD
+#if (__FreeBSD_version >= 600000)
         return ::gethostbyname_r (name.c_str (), result_buf,
                                   buf, buflen, result, h_errnop);
 #else
+	struct hostent *h;
+	h = gethostbyname (name.c_str());
+	if (h != NULL) {
+		memcpy(result_buf,h,sizeof(*h));
+		*result = h;
+		*h_errnop = 0;
+		return 0;
+	} else {
+		*h_errnop = 0;
+		return 1;
+	}
+#endif
+#endif
+#ifdef __GLIBC__
+        return ::gethostbyname_r (name.c_str (), result_buf,
+                                  buf, buflen, result, h_errnop);
         if (buflen < sizeof (hostent_data))
         {
             if (h_errnop != NULL)
