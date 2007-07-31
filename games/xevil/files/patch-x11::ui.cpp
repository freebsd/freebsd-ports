--- x11/ui.cpp.orig	2003-03-19 10:05:38.000000000 +0100
+++ x11/ui.cpp	2007-07-31 16:05:35.000000000 +0200
@@ -40,8 +40,9 @@
 #include <X11/Xatom.h>
 }
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <strstream>
+using namespace std;
 
 #include "coord.h"
 #include "area.h"
@@ -930,7 +931,7 @@
   UiP ui = (UiP)closure;
   ui->settingsChanges |= UIenemiesRefill;
   // SGI compiler says you can't cast void* to Boolean.
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   ui->settings.enemiesRefill = val;
 }
 
@@ -939,7 +940,7 @@
 void Ui::menu_controls_CB(void* value,Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     XMapWindow(ui->xvars.dpy[dpyNum],ui->xdata.controls[dpyNum]);
   }
@@ -955,7 +956,7 @@
                                 Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean active = (Boolean)(int)value;
+  Boolean active = (Boolean)(intptr_t)value;
 
   if (active) {
     ui->lControls[dpyNum].input = ui->lControls[dpyNum].key = 
@@ -994,7 +995,7 @@
 
 void Ui::menu_scenarios_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = SCENARIOS;
@@ -1005,7 +1006,7 @@
 
 void Ui::menu_levels_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = LEVELS;
@@ -1016,7 +1017,7 @@
 
 void Ui::menu_kill_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = KILL;
@@ -1027,7 +1028,7 @@
 
 void Ui::menu_duel_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = DUEL;
@@ -1038,7 +1039,7 @@
 
 void Ui::menu_extended_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = EXTENDED;
@@ -1049,7 +1050,7 @@
 
 void Ui::menu_training_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   if (val) {
     ui->settingsChanges |= UIstyle;
     ui->settings.style = TRAINING;
@@ -1070,7 +1071,7 @@
 void Ui::menu_cooperative_CB(void* value,Viewport*,void* closure) {
   UiP ui = (UiP)closure;
   ui->settingsChanges |= UIcooperative;
-  Boolean val = (Boolean)(int)value;
+  Boolean val = (Boolean)(intptr_t)value;
   ui->settings.cooperative = val;
 }
 
@@ -1079,7 +1080,7 @@
 void Ui::menu_help_CB(void* value,Viewport* vPort,void* closure) {
   UiP ui = (UiP)closure;
   int dpyNum = vPort->get_dpy_num();
-  Boolean active = (Boolean)(int)value;
+  Boolean active = (Boolean)(intptr_t)value;
 
   if (active) {
     XMapWindow(ui->xvars.dpy[dpyNum],ui->xdata.help[dpyNum]);
@@ -1094,7 +1095,7 @@
 void Ui::status_weapon_CB(void* value,Viewport* vPort,void*) {
   // Some mouse controls.
   //  UiP ui = (UiP)closure;
-  int button = (int)value;
+  intptr_t button = (intptr_t)value;
 
   switch (button) {
   case Button1:
@@ -1113,7 +1114,7 @@
 
 void Ui::status_item_CB(void* value,Viewport* vPort,void*) {
   //  UiP ui = (UiP)closure;
-  int button = (int)value;
+  intptr_t button = (intptr_t)value;
 
   switch (button) {
   case Button1:
