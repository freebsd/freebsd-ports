--- cmn/actual.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ cmn/actual.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -32,7 +32,7 @@
 
 // Include Files
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -122,6 +122,7 @@
 #include "bitmaps/yeti/yeti.bitmaps"
 
 
+using namespace std;
 
 ///// Some helper macros to define creatures with certain abilities.
 #define DEFINE_CREATURE_CTORS_2(CLASSNAME,ABILITY0,ability0,ABILITY1,ability1) \
@@ -454,9 +455,9 @@
     }
 	}
 
-	ostrstream msg;
-	msg << "Explosion hits " << hit << " objects." << ends;
-	locator->message_enq(msg.str());
+	stringstream msg;
+	msg << "Explosion hits " << hit << " objects.";
+	locator->message_enq(Utils::strdup(msg.str().c_str()));
 
 	kill_self();
 	Physical::act();
@@ -1001,7 +1002,7 @@
   if (other && (other->get_class_id() != A_AltarOfSin) &&
       (intel = other->get_intel())) {
     LocatorP locator = get_locator();
-    ostrstream str;
+    stringstream str;
     
     // Turned into a frog/baby seal.
     if (Utils::coin_flip() && other->is_moving() && 
@@ -1014,8 +1015,8 @@
       
       str << intel->get_name() << " attacks the Altar of Sin and is "
           << "turned into a " << (doFrog ? "frog" : "baby-seal")
-          << "." << ends;
-      locator->message_enq(str.str());
+          << ".";
+      locator->message_enq(Utils::strdup(str.str().c_str()));
   
       other->set_intel(NULL);
       if (!other->get_mapped()) {
@@ -1047,8 +1048,8 @@
     // Lose all health.
     else {
       str << "BLASPHMER!  " << intel->get_name() << 
-          " loses health for daring to attack the Altar of Sin." << ends;
-      locator->message_enq(str.str());
+          " loses health for daring to attack the Altar of Sin.";
+      locator->message_enq(Utils::strdup(str.str().c_str()));
       
       int damage = other->get_health();
       other->corporeal_attack(this,damage);
@@ -1075,8 +1076,8 @@
       (intel = other->get_intel()) && intel->is_human()) {
     int lives = intel->get_lives();
     LocatorP locator = get_locator();
-    ostrstream msg;
-    ostrstream arenaMsg;
+    stringstream msg;
+    stringstream arenaMsg;
 
     // Choose different blessings to give.
     int n = 0;
@@ -1112,8 +1113,8 @@
         }
         else {
           intel->set_lives(lives + 1);
-          msg << intel->get_name() << " sells soul for an extra life." << ends;
-          arenaMsg << "You Sold Your Soul For an Extra Life" << ends;
+          msg << intel->get_name() << " sells soul for an extra life.";
+          arenaMsg << "You Sold Your Soul For an Extra Life";
         }
         break;
     
@@ -1123,8 +1124,8 @@
         mod = new DoubleSpeed();
         assert(mod);          
         modList->append_unique(mod);
-        msg << intel->get_name() << " sells soul for Double Speed." << ends;
-        arenaMsg << "Double Speed" << ends;
+        msg << intel->get_name() << " sells soul for Double Speed.";
+        arenaMsg << "Double Speed";
         break;
 
         
@@ -1138,9 +1139,8 @@
         mod = new DoubleJump();
         assert(mod);          
         modList->append_unique(mod);
-        msg << intel->get_name() << " sells soul for extra jumping powers." 
-            << ends;
-        arenaMsg << "Extra Jumping Powers" << ends;
+        msg << intel->get_name() << " sells soul for extra jumping powers.";
+        arenaMsg << "Extra Jumping Powers";
         break;
         
 
@@ -1157,8 +1157,8 @@
         // So max health takes effect immediately.
         other->heal();
         
-        msg << intel->get_name() << " sells soul for Double Health." << ends;
-        arenaMsg << "Double Health" << ends;
+        msg << intel->get_name() << " sells soul for Double Health.";
+        arenaMsg << "Double Health";
         break;
 
 
@@ -1176,8 +1176,8 @@
           // Might as well make sure they can take advantage of it now.  
           other->heal();
 
-          msg << intel->get_name() << " sells soul for Healing Powers." << ends;
-          arenaMsg << "Healing Powers" << ends;
+          msg << intel->get_name() << " sells soul for Healing Powers.";
+          arenaMsg << "Healing Powers";
         }
         break;
 
@@ -1193,8 +1193,8 @@
           // Already checked that other is a Creature().
           ((CreatureP)other)->add_ability(a);
 
-          msg << intel->get_name() << " sells soul for HellFire Powers." << ends;
-          arenaMsg << "HellFire Powers" << ends;    
+          msg << intel->get_name() << " sells soul for HellFire Powers.";
+          arenaMsg << "HellFire Powers";
         }
         break;
 
@@ -1217,8 +1217,8 @@
           // Already checked that other is a Creature().
           ((CreatureP)other)->add_ability(a);
 
-          msg << intel->get_name() << " sells soul for Fireballs." << ends;
-          arenaMsg << "Fireballs" << ends;    
+          msg << intel->get_name() << " sells soul for Fireballs.";
+          arenaMsg << "Fireballs";
         }
         break;
         
@@ -1241,8 +1241,8 @@
           // Already checked that other is a Creature().
           ((CreatureP)other)->add_ability(a);
 
-          msg << intel->get_name() << " sells soul for Flying Powers." << ends;
-          arenaMsg << "Flying Powers" << ends;
+          msg << intel->get_name() << " sells soul for Flying Powers.";
+          arenaMsg << "Flying Powers";
         }
         break;
 
@@ -1274,8 +1274,8 @@
           // Already checked that other is a Creature().
           ((CreatureP)other)->add_ability(a);
 
-          msg << intel->get_name() << " sells soul for Sticky Powers." << ends;
-          arenaMsg << "Sticky Powers" << ends;          
+          msg << intel->get_name() << " sells soul for Sticky Powers.";
+          arenaMsg << "Sticky Powers";
         }
         break;
 
@@ -1285,8 +1285,8 @@
       }
     } // while
       
-    locator->message_enq(msg.str());
-    locator->arena_message_enq(arenaMsg.str(),other);
+    locator->message_enq(Utils::strdup(msg.str().c_str()));
+    locator->arena_message_enq(Utils::strdup(arenaMsg.str().c_str()),other);
 
     kill_self();
     turnTaken = True;
@@ -1534,7 +1534,7 @@
                                                  void *closure) {
   // notThis is used to prevent transmogifying into the same class an object
   // already is.
-  ClassId notThis = (ClassId)closure;
+  ClassId notThis = (long)closure;
   if (pc->classId == notThis) {
     return False;
   }
@@ -2087,10 +2087,9 @@
 		PhysicalP seal = new Seal(w,l,pos);
 		assert(seal);
 
-		char sealStr[20];
-		ostrstream str(sealStr,20);
-		str << "seal-" << sealsNum << ends;
-		NeutralP sealIntel = new SealIntel(w,l,sealStr,homeId);
+		stringstream str;
+		str << "seal-" << sealsNum;
+		NeutralP sealIntel = new SealIntel(w,l,Utils::strdup(str.str().c_str()),homeId);
 		seal->set_intel(sealIntel);
 		l->register_neutral(sealIntel);
 		seals[sealsNum] = sealIntel->get_intel_id();
