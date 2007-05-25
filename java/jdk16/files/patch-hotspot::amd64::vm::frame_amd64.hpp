--- ../../hotspot/src/cpu/amd64/vm/frame_amd64.hpp.orig	Tue Oct 19 14:41:26 2004
+++ ../../hotspot/src/cpu/amd64/vm/frame_amd64.hpp	Thu May 24 15:55:55 2007
@@ -125,5 +125,5 @@
   inline address* sender_pc_addr() const;
 
   // return address of param, zero origin index.
-  inline address* frame::native_param_addr(int idx) const;
+  inline address* native_param_addr(int idx) const;
   
