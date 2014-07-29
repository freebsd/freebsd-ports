--- cmn/physical.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/physical.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -33,10 +33,10 @@
 // Include Files
 #include "xdata.h"
 #include "physical.h"
-#include <iostream.h>
+#include <iostream>
 
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -54,6 +54,7 @@
 
 #include "bitmaps/transform/transform.bitmaps"
 
+using namespace std;
 
 // Defines
 #define VEL_SMALL 1
@@ -523,9 +524,9 @@
       
     if (heat == 0 && heatNext > 0) {
       LocatorP l = get_locator();
-      ostrstream str;
-      str << get_class_name() << " is on fire." << ends;
-      locator->message_enq(str.str());
+      stringstream str;
+      str << get_class_name() << " is on fire.";
+      locator->message_enq(Utils::strdup(str.str().c_str()));
     }
   }
   previousHeatWasSecondary = secondary;
@@ -1844,7 +1845,7 @@
   }
 
   // Use the pixmap resource id as the base.
-  u_int cmnBitsId = (unsigned int)mc->pixmapBits[baseDir][animNum];
+  u_int cmnBitsId = (unsigned long)mc->pixmapBits[baseDir][animNum];
 
   // It is ok to call OneTransform::compute_key() even if there is no 
   // transformation, will just return 0x0.  
@@ -2556,17 +2557,17 @@
 
 void Item::die() {
   LocatorP locator = get_locator();
-  ostrstream msg;
+  stringstream msg;
   switch (dieMessage) {
   case NONE:
     break;
   case USED:
-    msg << get_class_name() << " has been used." << ends;
-    locator->message_enq(msg.str());
+    msg << get_class_name() << " has been used.";
+    locator->message_enq(Utils::strdup(msg.str().c_str()));
     break;
   case DESTROYED:
-    msg << get_class_name() << " is destroyed." << ends;
-    locator->message_enq(msg.str());
+    msg << get_class_name() << " is destroyed.";
+    locator->message_enq(Utils::strdup(msg.str().c_str()));
     break;
   };
 
@@ -2650,10 +2651,8 @@
   // Prevent non-biologicals from picking up drugs.
 
   if (p->is_creature() && !((CreatureP)p)->biological()) {
-    ostrstream msg;
-    msg << "Non-Biological Creatures Cannot Use Drugs" << ends;
     LocatorP locator = get_locator();
-    locator->arena_message_enq(msg.str(),p);
+    locator->arena_message_enq(Utils::strdup("Non-Biological Creatures Cannot Use Drugs"), p);
     kill_self();
   }
   else {
@@ -2673,13 +2672,11 @@
     assert(context->odChance >= 0);
     if (context->odChance && Utils::choose(context->odChance) == 0) {
       p->kill_self();
-      ostrstream msg;
-      msg << p->get_class_name() << " dies from crack overdose." << ends;
-      locator->message_enq(msg.str());
+      stringstream msg;
+      msg << p->get_class_name() << " dies from crack overdose.";
+      locator->message_enq(Utils::strdup(msg.str().c_str()));
       
-      ostrstream arenaMsg;
-      arenaMsg << "You Died From Drug Overdose" << ends;
-      locator->arena_message_enq(arenaMsg.str(),p);
+      locator->arena_message_enq(Utils::strdup("You Died From Drug Overdose"),p);
 
       set_quiet_death(); // so doesn't report "has been used" message.
     }    
@@ -2693,9 +2690,7 @@
   }
   else {
     // Shouldn't get here, should kill self when picking it up.
-    ostrstream msg;
-    msg << "Non-Biological Creatures Cannot Use Drugs" << ends;
-    locator->arena_message_enq(msg.str(),p);
+    locator->arena_message_enq(Utils::strdup("Non-Biological Creatures Cannot Use Drugs"),p);
   }
   
   kill_self();
@@ -4334,14 +4329,14 @@
   if (!get_quiet_death() && !alive() && 
       (corpseTimer.ready() || (get_health() < - cc->corpseHealth))) {
     LocatorP locator = get_locator();
-    ostrstream msg;
+    stringstream msg;
     if (corpseTimer.ready()) {
-	    msg << get_class_name() << " corpse has decomposed." << ends;
-	    locator->message_enq(msg.str());
+	    msg << get_class_name() << " corpse has decomposed.";
+	    locator->message_enq(Utils::strdup(msg.str().c_str()));
     }
     else {
-      msg << get_class_name() << " corpse has been destroyed." << ends;
-      locator->message_enq(msg.str());
+      msg << get_class_name() << " corpse has been destroyed.";
+      locator->message_enq(Utils::strdup(msg.str().c_str()));
     }
     set_delete_me();
   }
@@ -4399,9 +4394,9 @@
     set_vel_next(velNew);
     set_stance_next(CO_air);
     
-    ostrstream msg;
-    msg << get_class_name() << " has died." << ends;
-    locator->message_enq(msg.str());
+    stringstream msg;
+    msg << get_class_name() << " has died.";
+    locator->message_enq(Utils::strdup(msg.str().c_str()));
     
     set_no_death_delete();
   }
@@ -6072,10 +6067,10 @@
     }
     // If User is already holding the max number of weapons.
     else if (weaponsNum >= PH_WEAPONS_MAX) {
-      ostrstream msg;
-      msg << "Can only hold " << PH_WEAPONS_MAX << " weapons" << ends;          
+      stringstream msg;
+      msg << "Can only hold " << PH_WEAPONS_MAX << " weapons";
       LocatorP locator = cre->get_locator();
-      locator->arena_message_enq(msg.str(),cre);
+      locator->arena_message_enq(Utils::strdup(msg.str().c_str()),cre);
       destroyOther = True;
     }
     // Actually pick it up.
@@ -6124,15 +6119,14 @@
   else {
     LocatorP locator = cre->get_locator();
     if (itemsNum == PH_ITEMS_MAX) {
-      ostrstream msg;
-      msg << "Can only hold " << PH_ITEMS_MAX << " items" << ends;          
-      locator->arena_message_enq(msg.str(),cre);
+      stringstream msg;
+      msg << "Can only hold " << PH_ITEMS_MAX << " items";
+      locator->arena_message_enq(Utils::strdup(msg.str().c_str()),cre);
     }
     else if (itemClassCount >= ITEM_CLASS_MAX) {
-      ostrstream msg;
-      msg << "Can only hold " << ITEM_CLASS_MAX 
-        << " of any one item" << ends;
-      locator->arena_message_enq(msg.str(),cre);
+      stringstream msg;
+      msg << "Can only hold " << ITEM_CLASS_MAX << " of any one item";
+      locator->arena_message_enq(Utils::strdup(msg.str().c_str()),cre);
     }
 
     other->set_quiet_death();
@@ -6661,9 +6655,9 @@
         ((ItemP)p)->use(cre);
       }
       else {
-        ostrstream str;
-        str << "Cannot use " << p->get_class_name() << ends;
-        locator->arena_message_enq(str.str(),cre);
+        stringstream str;
+        str << "Cannot use " << p->get_class_name();
+        locator->arena_message_enq(Utils::strdup(str.str().c_str()),cre);
       }
     }
     break;        
