--- src/script_manager.cpp.orig	2007-06-12 21:32:05.000000000 +0400
+++ src/script_manager.cpp	2009-07-28 23:45:51.000000000 +0400
@@ -130,7 +130,7 @@
       {
         squirrel_vm.waiting_for_events = WakeupData(NO_EVENT);
         try {
-          if(sq_wakeupvm(squirrel_vm.vm, false, false, true) < 0) {
+          if(sq_wakeupvm(squirrel_vm.vm, false, false, true, false) < 0) {
             throw SquirrelError(squirrel_vm.vm, "Couldn't resume script");
           }
         } catch(std::exception& e) {
