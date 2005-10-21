--- tty.c.orig	Fri May  6 17:26:17 2005
+++ tty.c	Fri May  6 17:28:19 2005
@@ -934,9 +934,11 @@
 #endif
 
 #ifndef SETPGRP_VOID
-			setpgrp(0, 0);
-#else
-			setpgrp();
+			setpgrp(0, getpid());
+/*
+ * #else
+ * setpgrp();
+ */
 #endif
 
 			for (x = 0; x != 32; ++x)
