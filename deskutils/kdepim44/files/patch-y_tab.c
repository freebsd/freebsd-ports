--- kpilot/conduits/vcalconduit/versit/y_tab.c	Thu Jul 27 01:57:09 2000
+++ kpilot/conduits/vcalconduit/versit/y_tab.c.new	Mon Jun  3 05:51:54 2002
@@ -109,7 +109,7 @@
 #endif
 
 #include <string.h>
-#ifndef __MWERKS__
+#if !defined(__MWERKS__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include <stdio.h>
