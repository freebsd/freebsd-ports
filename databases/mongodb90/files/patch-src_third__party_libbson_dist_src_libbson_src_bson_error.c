--- src/third_party/libbson/dist/src/libbson/src/bson/error.c.orig	2026-09-29 00:00:00 UTC
+++ src/third_party/libbson/dist/src/libbson/src/bson/error.c
@@ -134,6 +134,6 @@ bson_strerror_r(int err_code,                    /* IN
    (void)strerror_r(err_code, buf, buflen);
    ret = buf;
-#elif defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700
+#elif defined(__FreeBSD__) || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700)
    // The behavior (of `strerror_l`) is undefined if the locale argument to
    // `strerror_l()` is the special locale object LC_GLOBAL_LOCALE or is not a
    // valid locale object handle.
