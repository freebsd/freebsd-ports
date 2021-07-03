--- src/util/os_file.c.orig	2021-06-30 18:18:56 UTC
+++ src/util/os_file.c
@@ -89,7 +89,7 @@ typedef ptrdiff_t ssize_t;
 static ssize_t
 readN(int fd, char *buf, size_t len)
 {
-   int err = -ENODATA;
+   int err = -1;
    size_t total = 0;
    do {
       ssize_t ret = read(fd, buf + total, len - total);
