--- include/ircsprintf.h.orig	Wed Dec 27 21:28:44 2006
+++ include/ircsprintf.h	Wed Dec 27 21:29:34 2006
@@ -3,6 +3,10 @@
 #include <stdarg.h>
 #include <stdio.h>
 
+#ifndef va_copy
+#define va_copy(a1, a2)	(a1) = (a2)
+#endif
+
 /* define this if you intend to use ircsnprintf or ircvsnprintf */
 /* It's not used, and sNprintf functions are not in all libraries */
 #define WANT_SNPRINTF
