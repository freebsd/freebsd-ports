--- ./fam/Listener.c++.orig	2003-04-15 06:52:40.000000000 +0200
+++ ./fam/Listener.c++	2014-01-03 02:35:10.000000000 +0100
@@ -36,6 +36,10 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <stdlib.h>
+#endif // __FreeBSD__
 
 #include <errno.h>
 
@@ -203,7 +207,7 @@
     //  requested user and pass the name back to the client.
 
     //  Unset TMPDIR to ensure that tempnam() works as desired
-    putenv("TMPDIR=");
+    unsetenv("TMPDIR");
 
     char *tmpfile = tempnam("/tmp", ".fam");
 #if defined(__FreeBSD__)
