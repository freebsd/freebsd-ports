--- src/util/os_file.c.orig	2020-10-05 09:57:28 UTC
+++ src/util/os_file.c
@@ -80,7 +80,7 @@ os_dupfd_cloexec(int fd)
 #endif
 
 
-#if DETECT_OS_LINUX
+#if DETECT_OS_LINUX || DETECT_OS_FREEBSD
 
 #include <fcntl.h>
 #include <sys/stat.h>
@@ -93,7 +93,11 @@ os_dupfd_cloexec(int fd)
 static ssize_t
 readN(int fd, char *buf, size_t len)
 {
+#if DETECT_OS_LINUX
    int err = -ENODATA;
+#elif DETECT_OS_FREEBSD
+   int err = -1;
+#endif
    size_t total = 0;
    do {
       ssize_t ret = read(fd, buf + total, len - total);
@@ -185,6 +189,7 @@ os_read_file(const char *filename, size_t *size)
    return buf;
 }
 
+#if DETECT_OS_LINUX
 int
 os_same_file_description(int fd1, int fd2)
 {
@@ -196,6 +201,18 @@ os_same_file_description(int fd1, int fd2)
 
    return syscall(SYS_kcmp, pid, pid, KCMP_FILE, fd1, fd2);
 }
+#else
+int
+os_same_file_description(int fd1, int fd2)
+{
+   /* Same file descriptor trivially implies same file description */
+   if (fd1 == fd2)
+      return 0;
+
+   /* Otherwise we can't tell */
+   return -1;
+}
+#endif
 
 #else
 
