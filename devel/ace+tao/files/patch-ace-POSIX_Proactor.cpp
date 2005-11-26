--- ace/POSIX_Proactor.cpp.orig	Sat Nov 26 23:06:35 2005
+++ ace/POSIX_Proactor.cpp	Sat Nov 26 23:19:24 2005
@@ -26,6 +26,10 @@
 #  include "ace/OS_NS_strings.h"
 #endif /* sun */
 
+#if defined __FreeBSD__
+#include <sys/param.h>
+#endif
+
 // *********************************************************************
 /**
  * @class ACE_POSIX_Wakeup_Completion
@@ -1693,7 +1697,7 @@
 
   // Set the signal information.
   sigval value;
-#if defined (__FreeBSD__)
+#if (defined (__FreeBSD__) && __FreeBSD_version <= 700004)
   value.sigval_int = -1;
 #else
   value.sival_int = -1;
