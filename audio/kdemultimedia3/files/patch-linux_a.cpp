--- kmidi/linux_a.cpp	Fri Jan 19 10:17:50 2001
+++ kmidi/linux_a.cpp.new	Wed Jun 12 22:31:51 2002
@@ -38,7 +38,7 @@
 
 #ifdef __FreeBSD__
 #include <stdio.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #ifdef __bsdi__
