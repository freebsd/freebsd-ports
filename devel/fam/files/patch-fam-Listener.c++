--- fam/Listener.c++~	Tue Jul 16 02:14:41 2002
+++ fam/Listener.c++	Tue Sep  3 19:53:27 2002
@@ -35,6 +35,10 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <stdlib.h>
+#endif // __FreeBSD__
 
 #include <errno.h>
 
