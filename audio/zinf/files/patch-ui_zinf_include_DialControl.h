--- ui/zinf/include/DialControl.h.orig	2003-09-16 17:35:32 UTC
+++ ui/zinf/include/DialControl.h
@@ -24,7 +24,9 @@ ________________________________________
 #ifndef INCLUDED_DIALCONTROL_H__
 #define INCLUDED_DIALCONTROL_H__
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include "config.h"
 
 #include <string>
