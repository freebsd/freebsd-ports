$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/runtime/mutexLocker.cpp	17 Aug 2001 22:56:20 -0000	1.1.1.2
+++ ../../hotspot1.3.1/src/share/vm/runtime/mutexLocker.cpp	27 Jul 2003 10:41:16 -0000	1.2
@@ -90,7 +90,7 @@
 #endif
 
 #define def(var, type, pri, vm_block) \
-  var = new type(Mutex::##pri, #var, vm_block)
+  var = new type(Mutex::pri, #var, vm_block)
 
 void mutex_init() {  
   def(Patching_lock                , Mutex  , leaf,        true );  
