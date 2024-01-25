--- src/util/os_file.c.orig	2024-01-25 12:45:07 UTC
+++ src/util/os_file.c
@@ -207,13 +207,19 @@ os_same_file_description(int fd1, int fd2)
 int
 os_same_file_description(int fd1, int fd2)
 {
+#ifdef SYS_kcmp
    pid_t pid = getpid();
+#endif
 
    /* Same file descriptor trivially implies same file description */
    if (fd1 == fd2)
       return 0;
 
+#ifdef SYS_kcmp
    return syscall(SYS_kcmp, pid, pid, KCMP_FILE, fd1, fd2);
+#else
+   return -1;
+#endif
 }
 
 #else
