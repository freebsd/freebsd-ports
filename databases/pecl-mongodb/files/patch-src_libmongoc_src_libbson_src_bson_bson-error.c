--- src/libmongoc/src/libbson/src/bson/bson-error.c.orig	2023-05-09 08:13:22 UTC
+++ src/libmongoc/src/libbson/src/bson/bson-error.c
@@ -109,8 +109,6 @@ bson_strerror_r (int err_code,  /* IN */
    if (strerror_s (buf, buflen, err_code) != 0) {
       ret = buf;
    }
-#elif defined(__GNUC__) && defined(_GNU_SOURCE)
-   ret = strerror_r (err_code, buf, buflen);
 #else /* XSI strerror_r */
    if (strerror_r (err_code, buf, buflen) == 0) {
       ret = buf;
