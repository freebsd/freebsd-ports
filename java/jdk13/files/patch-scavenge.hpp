$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/memory/scavenge.hpp	11 Jul 2001 21:33:24 -0000	1.1.1.1
+++ ../../hotspot1.3.1/src/share/vm/memory/scavenge.hpp	22 Nov 2004 17:19:42 -0000
@@ -91,6 +91,9 @@
   // fill the new generation large dummy objects
   static void fill_newgen();
 
+  // Scavenge entry point called from VM operation
+  static void invoke_at_safepoint(int size_to_be_allocated, bool deferred, bool& notify_ref_lock);
+
  private:
   // Scavenge functions and java/lang/ref handling
   static void scavenge_oop(oop* p);
@@ -121,9 +124,6 @@
 
   static void compute_scavenge_functions();
  
-  // Scavenge entry point called from VM operation
-  static void invoke_at_safepoint(int size_to_be_allocated, bool deferred, bool& notify_ref_lock);
-
   // Cheney scan
   static void evacuate_followers();
 
