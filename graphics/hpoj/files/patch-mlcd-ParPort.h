--- mlcd/ParPort.h.orig	Tue Mar 30 18:42:02 2004
+++ mlcd/ParPort.h	Tue Mar 30 18:51:23 2004
@@ -32,6 +32,10 @@
 	#include <unistd.h>
 	#include <fcntl.h>
     extern "C" {
+	#undef fls
+	#define fls iamdirtybutloved
+	#undef ffs__ParPort
+	#define ffs__ParPort iamdirtybutfancied
 	#include <machine/cpufunc.h>
     }
 #else
