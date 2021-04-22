--- rts/System/Platform/Linux/Futex.h.orig	2020-12-26 12:45:43 UTC
+++ rts/System/Platform/Linux/Futex.h
@@ -8,7 +8,7 @@
 #include "System/Misc/SpringTime.h"
 
 
-
+#ifndef __FreeBSD__
 class spring_futex
 {
 private:
@@ -32,6 +32,7 @@ class spring_futex (public)
 protected:
 	native_type mtx;
 };
+#endif
 
 /*FIXME
 class recursive_futex
