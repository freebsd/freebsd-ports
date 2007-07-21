Index: screen.c
@@ -23,7 +23,11 @@
 #include <options.h>
 #include <screen.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 
 #define LEFT        10
 #define RIGHT       10
