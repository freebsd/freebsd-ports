
$FreeBSD$

--- xmms_a.c.orig	Sat Oct 26 23:38:05 2002
+++ xmms_a.c	Sat Oct 26 23:38:08 2002
@@ -37,7 +37,7 @@
 #include <stdio.h>
 
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #include "mid.h"
