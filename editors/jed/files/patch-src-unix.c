--- src/unix.c.orig	Wed Oct 13 14:52:19 2004
+++ src/unix.c	Wed Oct 13 14:52:32 2004
@@ -722,7 +722,7 @@
 # endif
 #endif
 
-   *mode = m & 0777;
+   *mode = m & 07777;
 
    if (S_ISDIR(m)) return (2);
    return(1);
