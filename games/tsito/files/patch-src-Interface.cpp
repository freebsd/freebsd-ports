--- src/Interface.cpp.orig	Mon Jun  9 21:07:05 2003
+++ src/Interface.cpp	Sat Oct 16 01:43:23 2004
@@ -5,6 +5,8 @@
 #include	<windows.h>
 #include	<conio.h>
 #else
+#include	<sys/types.h>
+#include	<sys/time.h>
 #include	<sys/select.h>
 #include	<unistd.h>
 #endif
