$FreeBSD$

--- ListView.h.orig	Sun Nov 16 13:56:31 1997
+++ ListView.h	Wed Feb 18 10:31:19 2004
@@ -12,12 +12,7 @@
 #include <qdialog.h>
 #include "MultiListBox.h"
 
-#ifdef FreeBSD
-#include <machine/soundcard.h>
-#endif
-#ifdef Linux
 #include <sys/soundcard.h>
-#endif
 
 #define DEVICE 0
 #define MIXER "/dev/mixer"
