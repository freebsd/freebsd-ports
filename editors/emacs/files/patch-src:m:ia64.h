--- src/m/ia64.h.orig	Fri Sep 29 06:00:37 2000
+++ src/m/ia64.h	Thu Nov 20 13:44:02 2003
@@ -147,7 +147,7 @@
 
 #ifndef NOT_C_CODE
 /* We need these because pointers are larger than the default ints.  */
-# if !defined(__NetBSD__) && !defined(__OpenBSD__)
+# if !defined(__NetBSD__) && !defined(__OpenBSD__)  && !defined(__FreeBSD__)
 #  include <alloca.h>
 # else
 #  include <stdlib.h>
