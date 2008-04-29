--- src/emacs.c.orig	2006-09-20 04:29:27.000000000 +0200
+++ src/emacs.c	2008-03-23 18:38:20.000000000 +0100
@@ -48,7 +48,7 @@
 #endif
 
 #ifdef GNUSTEP
-#include <GSConfig.h>
+#include <GNUstepBase/GSConfig.h>
 #endif
 
 #include "lisp.h"
