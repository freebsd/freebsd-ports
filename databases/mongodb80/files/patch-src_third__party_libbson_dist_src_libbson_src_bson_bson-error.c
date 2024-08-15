--- src/third_party/libbson/dist/src/libbson/src/bson/bson-error.c.orig	2024-07-04 10:59:36 UTC
+++ src/third_party/libbson/dist/src/libbson/src/bson/bson-error.c
@@ -130,7 +130,7 @@ bson_strerror_r (int err_code,                    /* I
    // required) by the POSIX spec (see:
    // https://pubs.opengroup.org/onlinepubs/9699919799/functions/strerror.html#tag_16_574_08).
    (void) strerror_r (err_code, buf, buflen);
-#elif defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700
+#elif defined(__FreeBSD__) || ( defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 700 )
    // The behavior (of `strerror_l`) is undefined if the locale argument to
    // `strerror_l()` is the special locale object LC_GLOBAL_LOCALE or is not a
    // valid locale object handle.
