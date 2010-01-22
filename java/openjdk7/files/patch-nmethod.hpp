--- hotspot/src/share/vm/code/nmethod.hpp	Tue Jan 05 11:16:09 2010 -0800
+++ hotspot/src/share/vm/code/nmethod.hpp	Tue Jan 05 16:12:26 2010 -0800
@@ -255,7 +255,7 @@ class nmethod : public CodeBlob {
   const char* reloc_string_for(u_char* begin, u_char* end);
   // Returns true if this thread changed the state of the nmethod or
   // false if another thread performed the transition.
-  bool make_not_entrant_or_zombie(int state);
+  bool make_not_entrant_or_zombie(unsigned int state);
   void inc_decompile_count();
 
   // used to check that writes to nmFlags are done consistently.
