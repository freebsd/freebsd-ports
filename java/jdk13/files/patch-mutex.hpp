$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/runtime/mutex.hpp	17 Aug 2001 22:56:19 -0000	1.1.1.2
+++ ../../hotspot1.3.1/src/share/vm/runtime/mutex.hpp	22 Nov 2004 17:19:42 -0000
@@ -55,7 +55,6 @@
   debug_only(Thread* _last_owner;) // the last thread to own the lock    
 #endif
   
-  void set_owner_implementation(Thread* owner)                        PRODUCT_RETURN;
   void trace                   (const char* operation)                PRODUCT_RETURN;
   void check_prelock_state     (Thread* thread)                       PRODUCT_RETURN;
   void check_block_state       (Thread* thread)                       PRODUCT_RETURN;
@@ -69,6 +68,7 @@
     _allow_vm_block_flag     = true
   };	
 
+  void set_owner_implementation(Thread* owner)                        PRODUCT_RETURN;
   Mutex(int prio, const char *name, bool allow_vm_block = !_allow_vm_block_flag);
   ~Mutex();
   
