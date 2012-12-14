--- x11/viewport.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/viewport.cpp	2012-05-27 06:52:59.000000000 +0900
@@ -44,8 +44,9 @@
 #include <X11/Xos.h>
 #include <X11/keysym.h>
 }
-#include <strstream.h>
+#include <sstream>
 
+using namespace std;
 
 #define TICK_BORDER_WIDTH 5 // border width big enough for a tick mark.
 #define TICK_WIDTH 3
@@ -60,14 +61,14 @@
 #define COL_SHIFT 4
 
 // Number of characters across for each menu button.
-#define QUIT_LINE_LENGTH 5
-#define NEW_GAME_LINE_LENGTH 9
+#define QUIT_LINE_LENGTH 4
+#define NEW_GAME_LINE_LENGTH 13
 #define HUMANS_NUM_LINE_LENGTH 9
 #define ENEMIES_NUM_LINE_LENGTH 11
 #define ENEMIES_REFILL_LINE_LENGTH 13
 #define CONTROLS_LINE_LENGTH 13
 #define LEARN_CONTROLS_LINE_LENGTH 12
-#define STYLE_LINE_LENGTH 11
+#define STYLE_LINE_LENGTH 16
 #define SCENARIOS_LINE_LENGTH 9
 #define LEVELS_LINE_LENGTH 6
 #define KILL_LINE_LENGTH 16
@@ -1056,20 +1057,18 @@
 
 void Viewport::set_menu_humans_num(int val) {
   assert(menusNum > menuHumansNum);
-  ostrstream str;
-  str << val << ends;
-  ((WritePanel *)menus[menuHumansNum])->set_value(str.str());
-  delete str.str();
+  stringstream str;
+  str << val;
+  ((WritePanel *)menus[menuHumansNum])->set_value(str.str().c_str());
 }
  
 
 
 void Viewport::set_menu_enemies_num(int val) {
   assert(menusNum > menuEnemiesNum);
-  ostrstream str;
-  str << val << ends;
-  ((WritePanel *)menus[menuEnemiesNum])->set_value(str.str());
-  delete str.str();
+  stringstream str;
+  str << val;
+  ((WritePanel *)menus[menuEnemiesNum])->set_value(str.str().c_str());
 }
 
 
@@ -1128,10 +1127,9 @@
 
 void Viewport::set_quanta(Quanta quanta) {
   assert(menusNum > menuQuanta);
-  ostrstream str;
-  str << quanta << ends;
-  ((WritePanel *)menus[menuQuanta])->set_value(str.str());
-  delete str.str();  
+  stringstream str;
+  str << quanta;
+  ((WritePanel *)menus[menuQuanta])->set_value(str.str().c_str());
 } 
 
 
@@ -1144,33 +1142,27 @@
 
 
 void Viewport::set_humans_playing(int val) {  
-  ostrstream msg;
+  stringstream msg;
   if (val == 1) {
-    msg << "1 Human" << ends;
+    msg << "1 Human";
   }
   else {
-    msg << val << " Humans" << ends;
+    msg << val << " Humans";
   }
-  char *msg_str = msg.str();
-  
-  humansPlaying->set_message(msg_str);
-  delete msg_str;
+  humansPlaying->set_message(msg.str().c_str());
 }
 
 
 
 void Viewport::set_enemies_playing(int val) {  
-  ostrstream msg;
+  stringstream msg;
   if (val == 1) {
-    msg << "1 Enemy" << ends; 
+    msg << "1 Enemy";
   }
   else {
-    msg << val << " Enemies" << ends; 
+    msg << val << " Enemies";
   }
-  char *msg_str = msg.str();
-  
-  enemiesPlaying->set_message(msg_str);
-  delete msg_str;
+  enemiesPlaying->set_message(msg.str().c_str());
 }
 
 
@@ -1632,7 +1624,7 @@
   // Would be much better to put the radio-button logic in the Panel classes.
   if (pClosure->radio) {
     // SGI compiler says you can't cast void* to Boolean.
-    Boolean bValue = (Boolean)(int)value;
+    Boolean bValue = (Boolean)(long)value;
     if (!bValue) {
       ((TogglePanel*)panel)->set_value(True);
     }
@@ -1701,7 +1693,7 @@
       pos.y += xvars.fontSize[dpyNum].height;
       
       for (int n = 0; n < DIFFICULTY_LEVELS_NUM; n++) {
-        ostrstream str;
+        stringstream str;
         str << "[" << n;
         if (n == DIFF_NORMAL) {
           str << ",space]  ";
@@ -1709,10 +1701,9 @@
         else {
           str << "]        ";
         }
-        str << difficultyLevels[n].name << ends;
+        str << difficultyLevels[n].name;
         pos.y += xvars.fontSize[dpyNum].height;
-        draw_string(pos,str.str());
-        delete str.str();
+        draw_string(pos,str.str().c_str());
       }
       
       XSetForeground(xvars.dpy[dpyNum],xvars.gc[dpyNum],
@@ -1733,7 +1724,7 @@
 
 
 
-void Viewport::draw_string(const Pos &pos,char *msg) {
+void Viewport::draw_string(const Pos &pos,const char *msg) {
   XDrawString(xvars.dpy[dpyNum],arena,
               xvars.gc[dpyNum],
               pos.x,pos.y + xvars.font[dpyNum]->max_bounds.ascent,
@@ -1930,7 +1921,7 @@
       new ButtonPanel(dpyNum,xvars,toplevel,
                       pos,newGameUnit,
                       Viewport::panel_callback,panelClosures.get(menuNewGame),
-                      "New Game");
+                      "New Game (F2)");
     assert(p);
     p->set_background(menuBg,False);
     pos.x += newGameUnit.width;
@@ -2016,7 +2007,7 @@
       new TextPanel(dpyNum,xvars,toplevel,
                     pos,styleUnit,
                     NULL,NULL,
-                    "Game style:");
+                    "Game style: (F3)");
     assert(p);
     //      p->set_background(menuBg,False);
     pos.x += styleUnit.width;
@@ -2194,33 +2185,24 @@
   }
 
   const IntelStatus *status = intel->get_intel_status();
+  statuses[statusName]->set_message(status->name);
+
+  statuses[statusClassName]->set_message(status->className);
   
-  ostrstream name;
-  name << status->name << ends;
-  statuses[statusName]->set_message(name.str());
-  delete name.str();
-
-  ostrstream className;
-  className << status->className << ends;
-  statuses[statusClassName]->set_message(className.str());
-  delete className.str();
-  
-  ostrstream health;
+  stringstream health;
   if (status->health == -1) {
-    health << "Dead" << ends;
+    health << "Dead";
   }
   else {
-    health << status->health << " Health" << ends; 
+    health << status->health << " Health";
   }
-  statuses[statusHealth]->set_message(health.str());
-  delete health.str();
+  statuses[statusHealth]->set_message(health.str().c_str());
   
-  ostrstream mass;
-  mass << status->mass << " Mass" << ends;
-  statuses[statusMass]->set_message(mass.str());
-  delete mass.str();
+  stringstream mass;
+  mass << status->mass << " Mass";
+  statuses[statusMass]->set_message(mass.str().c_str());
   
-  ostrstream weapon;
+  stringstream weapon;
   if (status->weaponClassId == A_None) {
     weapon << "No Weapon";
   }
@@ -2230,62 +2212,56 @@
   if (status->ammo != PH_AMMO_UNLIMITED) {
     weapon << " (" << status->ammo << ")";
   }
-  weapon << ends;
   statuses[statusWeapon]->
     set_foreground(status->weaponReady ? 
                    xvars.green[dpyNum] : xvars.red[dpyNum],False);
-  statuses[statusWeapon]->set_message(weapon.str());
-  delete weapon.str();
+  statuses[statusWeapon]->set_message(weapon.str().c_str());
   
-  ostrstream item;
+  stringstream item;
   if (status->itemClassId == A_None) {
     item << "No Item";
   }
   else {
     item << status->item << " (" << status->itemCount << ")";
   }
-  item << ends;
-  statuses[statusItem]->set_message(item.str());
-  delete item.str();
+  statuses[statusItem]->set_message(item.str().c_str());
   
-  ostrstream livesHKills;
+  stringstream livesHKills;
   if (styleInfo->get_game_style_type() == EXTENDED) {
     // Takes soups into account.
     livesHKills << (status->humanKills - status->soups) 
-                << " Human Kills" << ends;
+                << " Human Kills";
   }
   else {
     if (status->lives == IT_INFINITE_LIVES) {
       // Does this case ever happen?  I don't think so.
-      livesHKills << "Unlimited Lives" << ends;
+      livesHKills << "Unlimited Lives";
     }
     else {
       if (status->lives == 1) {
-        livesHKills << "1 Life" << ends;
+        livesHKills << "1 Life";
       }
       else {
-        livesHKills << status->lives << " Lives" << ends;
+        livesHKills << status->lives << " Lives";
       }
     }
   }
-  statuses[statusLivesHKills]->set_message(livesHKills.str());
-  delete livesHKills.str();
+  statuses[statusLivesHKills]->set_message(livesHKills.str().c_str());
   
-  ostrstream killsMKills;
+  stringstream killsMKills;
   if (styleInfo->get_game_style_type() == EXTENDED) {
-    killsMKills << status->enemyKills << " Machine Kills" << ends;
+    killsMKills << status->enemyKills << " Machine Kills";
   }
   else {
     int kills = status->humanKills + status->enemyKills;
     if (kills == 1) {
-      killsMKills << "1 Kill" << ends;
+      killsMKills << "1 Kill";
     }
     else {
-      killsMKills << kills << " Kills" << ends;
+      killsMKills << kills << " Kills";
     }
   }
-  statuses[statusKillsMKills]->set_message(killsMKills.str());
-  delete killsMKills.str();
+  statuses[statusKillsMKills]->set_message(killsMKills.str().c_str());
 }
 
 
