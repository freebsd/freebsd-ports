Index: hack/hack.pager.c
@@ -367,6 +367,8 @@
 #else
 
 #ifdef BSD
+#include	<sys/wait.h>
+#elif POSIX
 #include	<sys/wait.h>
 #else
 #include	<wait.h>
