--- lib/include/tracer.hh.orig	2021-08-03 01:45:08 UTC
+++ lib/include/tracer.hh
@@ -28,9 +28,7 @@
 
 #include "vm_basic_defs.h"
 
-extern "C" {
 #include "glib.h"
-}
 
 
 #ifdef VMX86_DEVEL
