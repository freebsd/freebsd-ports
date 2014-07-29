--- cmn/game.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ cmn/game.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -31,16 +31,17 @@
 #include "stdafx.h"
 extern "C" {
 #include <string.h>
+#include <stdlib.h>
 }
 
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 #if WIN32
 #include <strstrea.h>
 #endif
 
-#include <iomanip.h>
+#include <iomanip>
 
 #include "utils.h"
 #include "coord.h"
@@ -123,7 +124,7 @@
 #define SOUNDONOFF_DEFAULT       True 
 
 
-char *Game::wittySayings[Game::WITTY_SAYINGS_NUM] = {
+const char *Game::wittySayings[Game::WITTY_SAYINGS_NUM] = {
     "If it moves it's a threat.  If it doesn't move it's a potential threat.",
     "Happy, happy.  Joy, joy.",
     "For the mother country!!!",
@@ -271,11 +272,19 @@
     "Prepare to Qualify.",
     "I got a bad feeling about this drop.",
     "Cowboys never quit!",
+    "The voices say I'm not crazy, so I'm OK!",
+    "Cure Sars!?!",
+    "Ha Ha Ha, Loser!",
+    "It's all fun and games until someone loses an eye.",
+    "Eye for an eye, tooth for a tooth.",
+    "Mo-o-m!",
+    "Timmy's touching me!",
+    "I'm not touching you! See? I'm not touching you!"
 };
 
 
 
-char *Game::intelNames[Game::INTEL_NAMES_NUM] = {
+const char *Game::intelNames[Game::INTEL_NAMES_NUM] = {
   "Dr. Pain",
   "Steve",
   "hardts",
@@ -350,6 +359,9 @@
   "Stan",
   "Mr. Hat",
   "Cid",
+  "Mr. Hankey",
+  "Michael Jackson",
+  "O.J. Simpson"
 };
 
 
@@ -793,7 +805,7 @@
 
   // Just for tracing in the debugger.
   char* version = Utils::get_OS_info();
-  delete version;
+  delete [] version;
 
   noUi = False;
   noNewLevel = False;
@@ -1056,7 +1068,7 @@
 
 Game::~Game() {
   if (oneItem) {
-    delete oneItem;
+    delete [] oneItem;
   }
 
   delete ui;
@@ -1500,13 +1512,13 @@
 
     if (mask & UIconnectServer) {
       delete role;
-      ostrstream portName;
-      portName << settings.connectPort << ends;
+      stringstream portName;
+      portName << settings.connectPort;
       IViewportInfo* vInfo = Ui::get_viewport_info();
-      ClientP client = new Client(settings.connectHostname,portName.str(),
+      ClientP client = new Client(settings.connectHostname,
+                                  Utils::strdup(portName.str().c_str()),
                                   0,settings.humanName,vInfo,
                                   Connection::ADJUST_SKIP,&locator);
-      delete portName.str();
       assert(client);
       role = client;
       ui->set_role_type(role->get_type());
@@ -1544,10 +1556,9 @@
       }
 
       delete role;
-      ostrstream portName;
-      portName << settings.serverPort << ends;
-      role = new Server(settings.localHuman,portName.str(),&locator);
-      delete portName.str();
+      stringstream portName;
+      portName << settings.serverPort;
+      role = new Server(settings.localHuman,portName.str().c_str(),&locator);
       assert(role);
       restartEnd = RE_RESTART;
       ui->set_role_type(role->get_type());
@@ -1573,9 +1584,9 @@
     ui->set_style(styleType);
   }
 
-  ostrstream str;
+  stringstream str;
   styleNext->describe(str);
-  locator.message_enq(str.str());
+  locator.message_enq(Utils::strdup(str.str().c_str()));
 }
 
 
@@ -1589,9 +1600,9 @@
     human->reincarnate();
     obj->set_intel(human);
       
-    ostrstream msg;
-    msg << human->get_name() << " is back from the dead." << ends;
-    locator.message_enq(msg.str());
+    stringstream msg;
+    msg << human->get_name() << " is back from the dead.";
+    locator.message_enq(Utils::strdup(msg.str().c_str()));
   }
 }
 
@@ -1615,7 +1626,7 @@
 void Game::new_level_check(int enemiesPlaying) {
   assert(state == gameOn);
 
-  ostrstream str;
+  stringstream str;
   Boolean lStrChanged = False;
   int val = style->new_level_check(enemiesPlaying,&world,&locator,
                                    level,lStrChanged,str,timer,
@@ -1645,11 +1656,8 @@
   // if str has anything in it.  Fucking Linux compilers.
   if (lStrChanged) {
     if (ui) {
-      ui->set_level(str.str());
+      ui->set_level(str.str().c_str());
     }
-    // Ok to delete even if ui is NULL, str.str() will allocate the memory to
-    // kill off.
-    delete str.str();
   }
 }  
 
@@ -1841,7 +1849,7 @@
 
 
 
-char *Game::choose_ranking(int kills) {
+const char *Game::choose_ranking(int kills) {
   // Figure out the ranking set, they are listed in order.
   int setNum = 0;
   assert(kills >= 0 && rankingSets[0].killsMin == 0);
@@ -1876,7 +1884,7 @@
   if (showMessages) {
     for (int n = 0; n < locator.humans_registered(); n++) {
       HumanP human = locator.get_human(n);
-      ostrstream msg;
+      stringstream msg;
 
       // Soups are only taken into account if you have unlimited lives.
       int totalKills;
@@ -1894,11 +1902,11 @@
         totalKills = human->get_human_kills() + human->get_enemy_kills();
       }
 
-      char *ranking = choose_ranking(totalKills);
+      const char *ranking = choose_ranking(totalKills);
       msg << totalKills << (totalKills == 1 ? "Kill" : " Kills") 
-        << ", Rank: " << ranking << ends;
+        << ", Rank: " << ranking;
       IntelId humanIntelId = human->get_intel_id();
-      locator.arena_message_enq(msg.str(),&humanIntelId,10000);
+      locator.arena_message_enq(Utils::strdup(msg.str().c_str()),&humanIntelId,10000);
     }
   }
 }
@@ -1919,8 +1927,8 @@
   // Will clean out non-persistent teams.
   locator.level_reset();
 
-  ostrstream lStr;       // For level box on the side of the ui->
-  ostrstream lTitleStr;  // For Ui title screen.
+  stringstream lStr;       // For level box on the side of the ui->
+  stringstream lTitleStr;  // For Ui title screen.
   Boolean doBonus;
 
   // Possibly increment level count number.
@@ -1960,7 +1968,7 @@
   if (doBonus) {
     delete levelTitleStored; // If it already exists.
     // Store levelTitle string for later use.
-    levelTitleStored = lTitleStr.str();
+    levelTitleStored = Utils::strdup(lTitleStr.str().c_str());
 
     // Tell user about the bonus.
     award_bonuses_now();
@@ -1970,13 +1978,12 @@
   }
   // Go to getBearings state.
   else {
-    get_bearings(lTitleStr.str());
+    get_bearings(Utils::strdup(lTitleStr.str().c_str()));
   }
   
   if (ui) {
-    ui->set_level(lStr.str());
+    ui->set_level(lStr.str().c_str());
   }
-  delete lStr.str();
 
   // Will pass in more info later.
   role->new_level(this,&world,&locator);
@@ -1997,7 +2004,7 @@
       continue;
     }
 
-    char* awardMsg = NULL;
+    const char* awardMsg = NULL;
     int count = 0;
     while (!awardMsg && count < AWARD_BONUS_TRIES) {
       count++;
@@ -2184,9 +2191,9 @@
   
   // Moved resetting world rooms to new_level(); 
 
-  ostrstream msg;
-  msg << wittySayings[Utils::choose(WITTY_SAYINGS_NUM)] << ends;
-  locator.message_enq(msg.str());
+  stringstream msg;
+  msg << wittySayings[Utils::choose(WITTY_SAYINGS_NUM)];
+  locator.message_enq(Utils::strdup(msg.str().c_str()));
 
   /* Don't need to call Ui::set_* because the new values originally came 
      from ui-> */
@@ -2242,41 +2249,39 @@
           { // Right keys.
             right[n][which] = 0;
             
-            ostrstream strm;
+            stringstream strm;
             if (which == 0)
-              strm << "right_" << keysNames[n] << ends;
+              strm << "right_" << keysNames[n];
             else
-              strm << "right_" << keysNames[n] << "_2" << ends;
-            char *option = strm.str();
+              strm << "right_" << keysNames[n] << "_2";
+            const string & option = strm.str();
             
             // Should we free value??
-            char *value = XGetDefault(ui->get_dpy(0),XEVIL_CLASS,option);
+            char *value = XGetDefault(ui->get_dpy(0),XEVIL_CLASS,option.c_str());
             if (value) {
               KeySym keysym = XStringToKeysym(value);
               if (keysym != NoSymbol)
                 right[n][which] = keysym;
             }
-            delete option;
 	      }
 	      
 	      { // Left Keys.
             left[n][which] = 0;
             
-            ostrstream strm;
+            stringstream strm;
             if (which == 0)
-              strm << "left_" << keysNames[n] << ends;
+              strm << "left_" << keysNames[n];
             else
-              strm << "left_" << keysNames[n] << "_2" << ends;
-            char *option = strm.str();
+              strm << "left_" << keysNames[n] << "_2";
+            const string & option = strm.str();
             
             // Should we free value??
-            char *value = XGetDefault(ui->get_dpy(0),XEVIL_CLASS,option);
+            char *value = XGetDefault(ui->get_dpy(0),XEVIL_CLASS,option.c_str());
             if (value) {
               KeySym keysym = XStringToKeysym(value);
               if (keysym != NoSymbol)
                 left[n][which] = keysym;
             }
-            delete option;
 	      }
 	    }
 
@@ -2291,10 +2296,10 @@
 void Game::parse_args(int *argc,char **argv) {
   // Create a bunch of "-name<x>" strings for comparing with command-line 
   // args.
-  ostrstream dashName[Locator::HUMANS_MAX];
+  stringstream dashName[Locator::HUMANS_MAX];
   int n;
   for (n = 0; n < Locator::HUMANS_MAX; n++) {
-    dashName[n] << "-name" << n << ends;
+    dashName[n] << "-name" << n;
   }
 
   // Defaults
@@ -2351,7 +2356,7 @@
     // Check "-name<x>" arguments.
     else {
       for (int j = 0; j < Locator::HUMANS_MAX; j++) {
-        if ((! strcmp(dashName[j].str(),argv[n])) && (n + 1 < *argc)) {
+        if ((! strcmp(dashName[j].str().c_str(),argv[n])) && (n + 1 < *argc)) {
           humanNames[j] = Utils::strdup(argv[n+1]);
           n++;
         }
@@ -2728,12 +2733,6 @@
       n++;
     }
   } // for
-  
-  
-  // Delete memory for "-name" strings.
-  for (n = 0; n < Locator::HUMANS_MAX; n++) {
-    delete dashName[n].str();
-  }
 }
 
 
@@ -2741,15 +2740,15 @@
 char **Game::display_names(int *argc,char **argv) {
 
 #if X11
-  ostrstream dashDisplay[UI_VIEWPORTS_MAX][2];
+  stringstream dashDisplay[UI_VIEWPORTS_MAX][2];
   char **displayNames = new charP [UI_VIEWPORTS_MAX];
 
   int n;
   for (n = 0; n < UI_VIEWPORTS_MAX; n++) {
     displayNames[n] = new char [Xvars::DISPLAY_NAME_LENGTH];
     strcpy(displayNames[n],"");
-    dashDisplay[n][0] << "-display" << n << ends;
-    dashDisplay[n][1] << "-d" << n << ends;
+    dashDisplay[n][0] << "-display" << n;
+    dashDisplay[n][1] << "-d" << n;
   }
 
   // Loop through all command line arguments.
@@ -2765,7 +2764,7 @@
     // Set display name for one viewport.
     for (int m = 0; m < UI_VIEWPORTS_MAX; m++) {
       for (int which = 0; which < 2; which++) {
-        if (!strcmp(argv[n],dashDisplay[m][which].str())) {
+        if (!strcmp(argv[n],dashDisplay[m][which].str().c_str())) {
           assert(strlen(argv[n+1]) < Xvars::DISPLAY_NAME_LENGTH);
           strcpy(displayNames[m],argv[n+1]);
         }
@@ -2773,11 +2772,6 @@
     }
   }
 
-  for (n = 0; n < UI_VIEWPORTS_MAX; n++) {
-    for (int which = 0; which < 2; which++) {
-      delete dashDisplay[n][which].str();
-    }
-  }
   return displayNames;
 #endif
 
@@ -2890,7 +2884,7 @@
   assert(role->get_type() != R_CLIENT);
 
   // Choose random name if -name was not specified for this player.
-  char *nameNonPc = 
+  const char *nameNonPc = 
     Utils::strlen(humanNames[h]) ? 
     humanNames[h] :
     intelNames[intelNamesIndices[h % INTEL_NAMES_NUM]];
@@ -2954,13 +2948,12 @@
   
   // Put message in the status bar when the game starts up.
   // Use \n in string for locator.message_enq.
-  ostrstream msg;
+  stringstream msg;
   msg 
     << "XEvil(TM) " << VERSION 
     << "  http://www.xevil.com  satan@xevil.com  " << XETP::versionStr << "\n"
-    << "Copyright(C) 1994,2000 Steve Hardt and Michael Judge"
-    << ends;
-  locator.message_enq(msg.str());
+    << "Copyright(C) 1994,2000 Steve Hardt and Michael Judge";
+  locator.message_enq(Utils::strdup(msg.str().c_str()));
 
 
   // Print message to standard out.  Doesn't really do anything on Windows.
@@ -3075,11 +3068,10 @@
   IntelOptions ops;
   ITmask opMask = intel_options_for(ops,obj->get_class_id());
 
-  ostrstream name;
-  name << "Machine-" << (enemyNameCount++) << ends;
-  EnemyP enemy = new Enemy(&world,&locator,name.str(),&ops,opMask);
+  stringstream name;
+  name << "Machine-" << (enemyNameCount++);
+  EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),&ops,opMask);
   assert(enemy);
-  delete name.str();
   locator.register_enemy(enemy);
 
   if (addToLocator) {
@@ -3235,14 +3227,13 @@
   switch (Utils::choose(8)) {
     case 0: { // A bunch of Heros and an Alien.
     	for (int n = 0; n < 10; n++) {
-        ostrstream name;
-        name << "Enemy-" << n << ends;
+        stringstream name;
+        name << "Enemy-" << n;
         IntelOptions ops;
         ops.harmless = True;
-        EnemyP enemy = new Enemy(&world,&locator,name.str(),
+        EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
 			         &ops,ITharmless);
         assert(enemy);
-        delete name.str();
         locator.register_enemy(enemy);
 
         Pos pos = world.empty_rect(Hero::get_size_max());
@@ -3268,16 +3259,15 @@
     
     case 1: { // Hero, FThrower, and a bunch of Frogs (does not mean Frenchmen).
 	    for (int n = 0; n < 15; n++) {
-	      ostrstream name;
-	      name << "Enemy-" << n << ends;
+	      stringstream name;
+	      name << "Enemy-" << n;
 	      IntelOptions ops;
 	      ops.psychotic = Utils::coin_flip();
-	      EnemyP enemy = new Enemy(&world,&locator,name.str(),
+	      EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
 					     &ops,ITpsychotic);
 	      assert(enemy);
-	      delete name.str();
 	      locator.register_enemy(enemy);
-	      
+
 	      Pos pos = world.empty_rect(Frog::get_size_max());
 	      PhysicalP obj = new Frog(&world,&locator,pos);
 	      assert(obj);
@@ -3304,15 +3294,14 @@
     case 2: { // A bunch of Enforcers.
       for (int n = 0; n < 10; n++)
 	      {
-	        ostrstream name;
-	        name << "Enemy-" << n << ends;
+	        stringstream name;
+	        name << "Enemy-" << n;
 	        IntelOptions ops;
 	        ops.classFriends = False;
 	        ops.psychotic = True;
-	        EnemyP enemy = new Enemy(&world,&locator,name.str(),
+	        EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
 					       &ops,ITclassFriends|ITpsychotic);
 	        assert(enemy);
-	        delete name.str();
 	        locator.register_enemy(enemy);
 	        
 	        Pos pos = world.empty_rect(Enforcer::get_size_max());
@@ -3327,14 +3316,13 @@
 
     case 3: { // A bunch of Ninjas and a chainsaw.
       for (int n = 0; n < 10; n++) {
-	      ostrstream name;
-	      name << "Enemy-" << n << ends;
+	      stringstream name;
+	      name << "Enemy-" << n;
 	      IntelOptions ops;
 	      ops.classFriends = False;
-	      EnemyP enemy = new Enemy(&world,&locator,name.str(),
+	      EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
 					     &ops,ITclassFriends);
 	      assert(enemy);
-	      delete name.str();
 	      locator.register_enemy(enemy);
 	      
 	      Pos pos = world.empty_rect(Ninja::get_size_max());
@@ -3373,12 +3361,11 @@
       }	    
 
       for (int m = 0; m < 10; m++) {
-        ostrstream name;
-        name << "Enemy-" << m << ends;
-        EnemyP enemy = new Enemy(&world,&locator,name.str(),
+        stringstream name;
+        name << "Enemy-" << m;
+        EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
                                  NULL,ITnone);
         assert(enemy);
-        delete name.str();
         locator.register_enemy(enemy);
         
         Pos pos = world.empty_rect(Hero::get_size_max());
@@ -3414,14 +3401,13 @@
     case 5: { // Ninjas and ChopperBoys.
       int n;
       for (n = 0; n < 10; n++) {
-	      ostrstream name;
-	      name << "Enemy-" << n << ends;
+	      stringstream name;
+	      name << "Enemy-" << n;
 	      IntelOptions ops;
 	      ops.classFriends = False;
-	      EnemyP enemy = new Enemy(&world,&locator,name.str(),
+	      EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),
 					     &ops,ITclassFriends);
 	      assert(enemy);
-	      delete name.str();
 	      locator.register_enemy(enemy);
 	        
 	      PhysicalP obj;
@@ -3458,11 +3444,10 @@
       // and the scenario isn't set up yet.
 
       for (n = 0; n < 9; n++) {
-        ostrstream name;
-        name << "Dog-" << n << ends;
-        EnemyP intel = new Enemy(&world,&locator,name.str(),NULL,ITnone);
+        stringstream name;
+        name << "Dog-" << n;
+        EnemyP intel = new Enemy(&world,&locator,name.str().c_str(),NULL,ITnone);
         assert(intel);
-        delete name.str();
         locator.register_enemy(intel);
 
         Pos pos = world.empty_rect(Dog::get_size_max());
@@ -3473,13 +3458,12 @@
   	  }
 
       for (n = 0; n < 3; n++) {
-        ostrstream name;
-        name << "Enemy-" << n << ends;
+        stringstream name;
+        name << "Enemy-" << n;
         IntelOptions ops;
         ops.harmless = True;
-        EnemyP enemy = new Enemy(&world,&locator,name.str(),&ops,ITharmless);
+        EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),&ops,ITharmless);
         assert(enemy);
-        delete name.str();
         locator.register_enemy(enemy);
 
         PhysicalP obj;
@@ -3510,13 +3494,12 @@
         Segmented::create_and_add_composite(ret,&world,&locator,Dragon::SEGMENTS_NUM,pos,
                                             Dragon::create,NULL);
         for (int m = 0; m < ret.length(); m++) {
-          ostrstream name;
-          name << "Enemy-" << n << ends;
+          stringstream name;
+          name << "Enemy-" << n;
           IntelOptions ops;
           ops.harmless = True;
-          EnemyP enemy = new Enemy(&world,&locator,name.str(),&ops,ITharmless);
+          EnemyP enemy = new Enemy(&world,&locator,name.str().c_str(),&ops,ITharmless);
           assert(enemy);
-          delete name.str();
           locator.register_enemy(enemy);
           PhysicalP p = (PhysicalP)ret.get(m);
           p->set_intel(enemy);
