--- konwert-1.8/bin/filterm.cc.old	Tue May 18 08:01:23 2004
+++ konwert-1.8/bin/filterm.cc	Tue May 18 08:02:01 2004
@@ -10,7 +10,8 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <pty.h>
+#include <limits.h>
+#include <libutil.h>
 
 #define WERSJA "1.8"
 
