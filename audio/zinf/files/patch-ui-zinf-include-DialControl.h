--- ui/zinf/include/DialControl.h.orig	Wed Sep 17 02:35:32 2003
+++ ui/zinf/include/DialControl.h	Mon Feb 16 12:46:03 2004
@@ -24,7 +24,9 @@
 #ifndef INCLUDED_DIALCONTROL_H__
 #define INCLUDED_DIALCONTROL_H__
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include "config.h"
 
 #include <string>
