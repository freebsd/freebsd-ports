--- tardy/tardy.cc.orig	Tue Jan 14 00:58:28 2003
+++ tardy/tardy.cc	Tue Jan 14 00:58:44 2003
@@ -22,6 +22,7 @@
 
 #include <vector>
 #include <ac/stdio.h> /* need for grp.h on OSF/1 */
+#include <sys/types.h>
 #include <grp.h>
 #include <pwd.h>
 
