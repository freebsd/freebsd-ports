--- Robot/register.c.orig	Tue Oct  7 14:47:40 2003
+++ Robot/register.c	Tue Oct  7 14:49:02 2003
@@ -16,7 +16,11 @@
 
 #include <stdio.h>
 #include <sys/utsname.h>
+#ifndef __STDC__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 
 #include <xview/xview.h>
 #include <xview/frame.h>
