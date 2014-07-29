--- x11/ui.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/ui.cpp	2012-05-27 06:52:59.000000000 +0900
@@ -30,6 +30,7 @@
 #include "utils.h"
 extern "C" {
 #include <string.h>
+#include <stdlib.h>
 #include <X11/Xutil.h>
 #ifdef OPENWOUND_XOS_STRLEN_HACK
 #define _strings_h
@@ -40,8 +41,8 @@
 #include <X11/Xatom.h>
 }
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <sstream>
 
 #include "coord.h"
 #include "area.h"
@@ -59,6 +60,7 @@
 #include "panel.h"
 #include "viewport.h"
 
+using namespace std;
 
 // Defines
 #define DEFAULT_BIG_FONT_NAME "-*-helvetica-*-r-*-*-18-*-*-*-*-*-*-*"
@@ -226,20 +228,6 @@
   for (int d = 0; d < xvars.dpyMax; d++) {
     xvars.alloc_named_color(d,"steelblue");
   }
-  
-  // Run the license agreement.
-  // Note: The license agreement will not be run if the user runs
-  // "xevil -server -no_ui".
-  // Must be after init_x().
-  Boolean reduceDraw = Viewport::get_reduce_draw();
-  Boolean accepted = 
-    LAgreement::check_accepted(largeViewport,smoothScroll,reduceDraw,
-                               xvars,0,argc,argv);
-  Viewport::set_reduce_draw(reduceDraw);
-  if (!accepted) {
-    // Should probably let game.cpp call exit.
-    exit(1);
-  }
 
   // Ick, this should be in init_x(), but we need to call init_x() before
   // running the License Agreement to get this information.
@@ -461,21 +449,27 @@
     }
   }
 
-  if (down) {
-    // Restart game if space pressed.
-    // This doesn't always work, the otherInput flag might get cleared 
-    // before it is used.
-    if (keycode == XKeysymToKeycode(xvars.dpy[dpyNum],XK_space)) {
-      otherInput = True;
+    // If function keys are assigned to movement, weapon or item functions,
+    // then this code will not get executed.
+  if (down && !found) {
+    // Pause Game
+    if (keycode == XKeysymToKeycode(xvars.dpy[dpyNum],XK_F1)) {
+      settingsChanges |= UIpause;
+      settings.pause = True;
     }
-
-    if (!found) {
-      // Undocumented pause key feature.
-      // Don't do pause if XK_F1 is used for something else.
-      if (keycode == XKeysymToKeycode(xvars.dpy[dpyNum],XK_F1)) {
-        settingsChanges |= UIpause;
-        settings.pause = True;
-      }
+    // New Game
+    if (keycode == XKeysymToKeycode(xvars.dpy[dpyNum],XK_F2)) {
+      settingsChanges |= UInewGame;
+    }
+    // Change game style
+    if (keycode == XKeysymToKeycode(xvars.dpy[dpyNum],XK_F3)) {
+      settingsChanges |= UIstyle;
+      settings.style = (settings.style + 1) % NUM_GAME_STYLES;
+
+        // Avoid the LEVELS_ONLY option. There was no button before
+	// I got here. Avoiding the ability to set it until I
+	// discover why
+      settings.style += (settings.style == LEVELS_ONLY) ? 1 : 0;
     }
   }
 }
@@ -865,7 +859,7 @@
       char *msg;
       if (msg = locator->message_deq()) {
         set_message(msg);
-        delete msg;
+        delete [] msg;
         messageTimer.set(MESSAGE_TIME);
       }
     }
@@ -930,7 +924,7 @@
   UiP ui = (UiP)closure;
   ui->settingsChanges |= UIenemiesRefill;
   // SGI compiler says you can't cast void* to Boolean.
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   ui->settings.enemiesRefill = val;
 }
 
@@ -939,7 +933,7 @@
 void Ui::menu_controls_CB(void* value,Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     XMapWindow(ui->xvars.dpy[dpyNum],ui->xdata.controls[dpyNum]);
   }
@@ -955,13 +949,13 @@
                                 Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean active = (Boolean)(int)value;
+  Boolean active = (Boolean)(long)value;
 
   if (active) {
     ui->lControls[dpyNum].input = ui->lControls[dpyNum].key = 
       ui->lControls[dpyNum].which = 0;
       
-    ostrstream str;
+    stringstream str;
     str << "There are 2 sets of controls for the players on the right and" 
         << "\n"
         << "left sides of the keyboard, respectively." << "\n"
@@ -979,10 +973,9 @@
         << " player enter the " 
         << (ui->lControls[dpyNum].which ? "second" : "first") 
         << " key for <" << ui->keysNames[ui->lControls[dpyNum].key] 
-        << ">." << ends;
+        << ">.";
     
-    ui->learnControls[dpyNum]->set_message(str.str());
-    delete str.str();
+    ui->learnControls[dpyNum]->set_message(str.str().c_str());
     XMapWindow(ui->xvars.dpy[dpyNum],ui->xdata.learnControls[dpyNum]);
   }
   else {
@@ -994,7 +987,7 @@
 
 void Ui::menu_scenarios_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = SCENARIOS;
@@ -1005,7 +998,7 @@
 
 void Ui::menu_levels_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = LEVELS;
@@ -1016,7 +1009,7 @@
 
 void Ui::menu_kill_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = KILL;
@@ -1027,7 +1020,7 @@
 
 void Ui::menu_duel_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = DUEL;
@@ -1038,7 +1031,7 @@
 
 void Ui::menu_extended_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = EXTENDED;
@@ -1049,7 +1042,7 @@
 
 void Ui::menu_training_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = TRAINING;
@@ -1070,7 +1063,7 @@
 void Ui::menu_cooperative_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
   ui->settingsChanges |= UIcooperative;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(long)value;
   ui->settings.cooperative = val;
 }
 
@@ -1079,7 +1072,7 @@
 void Ui::menu_help_CB(void* value,Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean active = (Boolean)(int)value;
+  Boolean active = (Boolean)(long)value;
 
   if (active) {
     XMapWindow(ui->xvars.dpy[dpyNum],ui->xdata.help[dpyNum]);
@@ -1094,7 +1087,7 @@
 void Ui::status_weapon_CB(void* value,Viewport* vPort,void*) {
   // Some mouse controls.
   //  UiP ui = (UiP)closure;
-  int button = (int)value;
+  long button = (long)value;
 
   switch (button) {
   case Button1:
@@ -1113,7 +1106,7 @@
 
 void Ui::status_item_CB(void* value,Viewport* vPort,void*) {
   //  UiP ui = (UiP)closure;
-  int button = (int)value;
+  long button = (long)value;
 
   switch (button) {
   case Button1:
@@ -1167,14 +1160,14 @@
     return;
   }
 
-  ostrstream str;
+  stringstream str;
   str << (ui->lControls[dpyNum].input ? "Left" : "Right") 
       << " player: The "
       << (ui->lControls[dpyNum].which ? "second" : "first") << " key for <" 
       << ui->keysNames[ui->lControls[dpyNum].key] << "> is "
       << XKeysymToString(XKeycodeToKeysym(ui->xvars.dpy[dpyNum],
 					  event->xkey.keycode,0))
-      << "." << "\n" << "\n";
+      << ".\n\n";
   ui->keycodes[dpyNum][ui->lControls[dpyNum].input]
     [ui->lControls[dpyNum].key][ui->lControls[dpyNum].which] =
       event->xkey.keycode;
@@ -1222,21 +1215,18 @@
       << " player enter the " 
       << (ui->lControls[dpyNum].which ? "second" : "first") 
       << " key for <" << keysNames[ui->lControls[dpyNum].key] 
-	<< ">." << ends;
+	<< ">.";
 
   // Add message in front of str.str().
-  ostrstream fullStr;
+  stringstream fullStr;
   if (ui->lControls[dpyNum].input == UI_KEYS_LEFT) {
     fullStr << "You may dismiss this dialog now if you only want to" << "\n"
-           << "set the controls for one player." 
-            << "\n" << "\n";
+           << "set the controls for one player.\n\n";
   }
-  fullStr << str.str() << ends;
-  delete str.str();
+  fullStr << str.str();
  
 
-  ui->learnControls[dpyNum]->set_message(fullStr.str());
-  delete fullStr.str();
+  ui->learnControls[dpyNum]->set_message(fullStr.str().c_str());
 
   ui->controls_redraw(dpyNum);
 }
@@ -1537,7 +1527,7 @@
   Line::set_text_columns(HELP_COLS);
   Page page(NULL,helpMessage);
   const PtrList& lines = page.get_lines();
-  ostrstream message;
+  stringstream message;
   for (int n = 0; n < lines.length(); n++) {
     Line* line = (Line*)lines.get(n);
     char* text = line->alloc_text();
@@ -1545,7 +1535,6 @@
     message << text << '\n';
     delete [] text;
   }
-  message << ends;
 
 
   for (int dpyNum = 0; dpyNum < xvars.dpyMax; dpyNum++) {
@@ -1564,10 +1553,8 @@
       new TextPanel(dpyNum,xvars,xdata.help[dpyNum],pos,size);
     assert(help[dpyNum]);    
 
-    help[dpyNum]->set_message(message.str());
+    help[dpyNum]->set_message(message.str().c_str());
   } // dpyNum
-
-  delete message.str();
 }
 
 
@@ -1621,7 +1608,7 @@
   // Loop through all keys.
   for (int n = 0; n < UI_KEYS_MAX; n++) {
     // String for right side.
-    strstream str0;
+    stringstream str0;
     str0 << keysNames[n] << ":  " << XKeysymToString(keymaps[0][n][0][0]);
     if (keymaps[0][n][0][1] && strlen(XKeysymToString(keymaps[0][n][0][1])))
       str0 << ", " << XKeysymToString(keymaps[0][n][0][1]);
@@ -1631,10 +1618,9 @@
 	      && strlen(XKeysymToString(keymaps[0][n][1][1])))
 	    str0 << ", " << XKeysymToString(keymaps[0][n][1][1]);
 	}
-    str0 << ends;
     
     // String for left side.
-    strstream str1;
+    stringstream str1;
     str1 << keysNames[n] << ":  " << XKeysymToString(keymaps[1][n][0][0]);
     if (keymaps[1][n][0][1] && strlen(XKeysymToString(keymaps[1][n][0][1]))) {
       str1 << ", " << XKeysymToString(keymaps[1][n][0][1]);
@@ -1645,7 +1631,6 @@
 	      && strlen(XKeysymToString(keymaps[1][n][1][1])))
 	    str1 << ", " << XKeysymToString(keymaps[1][n][1][1]);
 	}
-    str1 << ends;
     
     // Draw key on left side.
     if (n != IT_CHAT) {  // Chat meaningless for left player.
@@ -1653,16 +1638,14 @@
                   xvars.fontSize[dpyNum].width,
                   xvars.font[dpyNum]->max_bounds.ascent 
                   + p * xvars.fontSize[dpyNum].height,
-                  str1.str(),strlen(str1.str()));
+                  str1.str().c_str(),str1.str().length());
     }
     // Draw on right side.
     XDrawString(xvars.dpy[dpyNum],xdata.controls[dpyNum],xvars.gc[dpyNum],
                 xvars.fontSize[dpyNum].width * (CONTROLS_COLS / 2 + 1),
                 xvars.font[dpyNum]->max_bounds.ascent 
                 + (p++) * xvars.fontSize[dpyNum].height,
-                str0.str(),strlen(str0.str()));
-    delete str0.str();
-    delete str1.str();
+                str0.str().c_str(),str0.str().length());
   }
   p++;
   
@@ -1693,7 +1676,7 @@
 
 
 
-char *Ui::keysNames[UI_KEYS_MAX] = {
+const char *Ui::keysNames[UI_KEYS_MAX] = {
   "center",
   "right",
   "down_right",
@@ -1752,7 +1735,7 @@
 
 
 
-char* Ui::helpMessage = 
+const char* Ui::helpMessage = 
 "For full instructions, including NETWORK PLAY, see "
 "http://www.xevil.com/docs/instructions.html\n"
 "\n"
