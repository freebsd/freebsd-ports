--- ole/gen_guid.cpp	Sat Dec 23 17:12:09 2000
+++ ole/gen_guid.cpp	Thu Jan 18 11:46:44 2001
@@ -55,2 +55,4 @@
 } timespec;
+#else
+# include <sys/time.h>
 #endif
