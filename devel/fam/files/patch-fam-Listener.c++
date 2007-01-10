--- fam/Listener.c++.orig	Tue Apr 15 13:52:40 2003
+++ fam/Listener.c++	Thu Jan 11 05:28:45 2007
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
