--- gdb/defs.h	Thu Aug  1 10:18:32 2002
+++ gdb/defs.h	Sun Oct 13 10:44:10 2002
@@ -39,8 +39,6 @@
 #include <unistd.h>
 #endif
 
-#include "gdb_locale.h"
-
 /* For ``enum target_signal''.  */
 #include "gdb/signals.h"
 
@@ -57,6 +55,8 @@
    here and in all subsequent file inclusions.  */
 
 #include "ansidecl.h"
+
+#include "gdb_locale.h"
 
 #include <stdarg.h>		/* for va_list */
 
