--- src/butil/errno.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/butil/errno.cpp
@@ -52,7 +52,7 @@ int DescribeCustomizedErrno(
             return -1;
         }
     } else {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
         const int rc = strerror_r(error_code, tls_error_buf, ERROR_BUFSIZE);
         if (rc != EINVAL)
 #else
@@ -79,7 +79,7 @@ const char* berror(int error_code) {
         if (s) {
             return s;
         }
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
         const int rc = strerror_r(error_code, butil::tls_error_buf, butil::ERROR_BUFSIZE);
         if (rc == 0 || rc == ERANGE/*bufsize is not long enough*/) {
             return butil::tls_error_buf;
