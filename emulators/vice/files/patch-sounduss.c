--- src/sounddrv/sounduss.c.orig	Sun May 29 19:05:49 2005
+++ src/sounddrv/sounduss.c	Sat Dec  3 19:09:24 2005
@@ -30,7 +30,7 @@
    sound driver. For BSDI this uss sound driver should
    not be used either. */
 
-#if !defined(__FreeBSD__) && !defined(__bsdi__)
+#if !defined(__bsdi__)
 
 #include "vice.h"
 
