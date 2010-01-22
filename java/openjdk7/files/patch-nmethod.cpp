--- hotspot/src/share/vm/code/nmethod.cpp	Tue Jan 05 11:16:09 2010 -0800
+++ hotspot/src/share/vm/code/nmethod.cpp	Tue Jan 05 16:12:26 2010 -0800
@@ -1170,7 +1170,7 @@ void nmethod::log_state_change() const {
 }
 
 // Common functionality for both make_not_entrant and make_zombie
-bool nmethod::make_not_entrant_or_zombie(int state) {
+bool nmethod::make_not_entrant_or_zombie(unsigned int state) {
   assert(state == zombie || state == not_entrant, "must be zombie or not_entrant");
 
   // If the method is already zombie there is nothing to do
