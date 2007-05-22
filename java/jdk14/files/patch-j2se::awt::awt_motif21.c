$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/awt_motif21.c	14 Jan 2005 10:35:32 -0000	1.6
+++ ../../j2se/src/solaris/native/sun/awt/awt_motif21.c	8 May 2007 22:05:37 -0000
@@ -15,7 +15,7 @@
 #include "awt_p.h"
 #include "awt_Component.h"
 
-#if (XmVersion == 2001)
+#if (XmVersion >= 2001)
 #include <Xm/XmIm.h>
 #else
 #define XmPER_SHELL 0
