--- hexEdit.cxx.orig	2004-05-14 05:08:34 UTC
+++ hexEdit.cxx
@@ -250,27 +250,27 @@ Fl_Menu_Item HeMenubar::itemList[] = {
   {   UL"New", MM_CMD+'n', newCB, 0, 0, MM_MENUSTYLE },
   {   UL"Open...", MM_CMD+'o', openCB, 0, FL_MENU_DIVIDER, MM_MENUSTYLE },
   {   UL"Save", MM_CMD+'s', saveCB, 0, 0, MM_MENUSTYLE },
-  {   "Save "UL"As...", FL_SHIFT+MM_CMD+'s', saveAsCB, 0, 0, MM_MENUSTYLE },
+  {   "Save " UL"As...", FL_SHIFT+MM_CMD+'s', saveAsCB, 0, 0, MM_MENUSTYLE },
   {   UL"Close", MM_CMD+'w', closeCB, 0, FL_MENU_DIVIDER, MM_MENUSTYLE },
-  {   "E"UL"xit mickey", MM_CMD+'q', quitCB, 0, 0, MM_MENUSTYLE },
+  {   "E" UL"xit mickey", MM_CMD+'q', quitCB, 0, 0, MM_MENUSTYLE },
   {   0 },
   { UL"Edit", 0, 0, 0, FL_SUBMENU, MM_MENUSTYLE },
   {   UL"Undo", MM_CMD+'z', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
   {   UL"Redo", FL_SHIFT+MM_CMD+'z', 0, 0, FL_MENU_INACTIVE|FL_MENU_DIVIDER, 
     MM_MENUSTYLE },
-  {   "C"UL"ut", MM_CMD+'x', cutCB, 0, 0, MM_MENUSTYLE },
+  {   "C" UL"ut", MM_CMD+'x', cutCB, 0, 0, MM_MENUSTYLE },
   {   UL"Copy", MM_CMD+'c', copyCB, 0, 0, MM_MENUSTYLE },
   {   UL"Paste", MM_CMD+'v', pasteCB, 0, 0, MM_MENUSTYLE },
   {   UL"Delete", 0, 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
-  {   "Select "UL"All", MM_CMD+'a', 0, 0, FL_MENU_INACTIVE|FL_MENU_DIVIDER, 
+  {   "Select " UL"All", MM_CMD+'a', 0, 0, FL_MENU_INACTIVE|FL_MENU_DIVIDER,
     MM_MENUSTYLE },
   {   UL"Insert", MM_CMD+'i', insertModeCB, (void*)1, 0, MM_MENUSTYLE },
   {   UL"Overwrite", FL_SHIFT+MM_CMD+'i', insertModeCB, 0, 0, MM_MENUSTYLE },
   {   0 },
   { UL"Find", 0, 0, 0, FL_SUBMENU, MM_MENUSTYLE },
   {   UL"Find", MM_CMD+'f', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
-  {   "Find && "UL"Replace", MM_CMD+'h', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
-  {   "Find "UL"Next", MM_CMD+'g', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
+  {   "Find && " UL"Replace", MM_CMD+'h', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
+  {   "Find " UL"Next", MM_CMD+'g', 0, 0, FL_MENU_INACTIVE, MM_MENUSTYLE },
   {   0 },
   { UL"Help", 0, 0, 0, FL_SUBMENU, MM_MENUSTYLE },
   {   UL"About mickey...", 0, aboutCB, 0, 0, MM_MENUSTYLE },
@@ -342,12 +342,12 @@ void HeMenubar::pasteCB(Fl_Widget*, void*) {
 void HeMenubar::insertModeCB(Fl_Widget*, void *userdata) {
   //++ should the insert mode by per application or per document?
   if (!app->document()) return;
-  int i = (int)userdata;
+  int i = reinterpret_cast<intptr_t>(userdata);
   app->document()->manager()->insertMode(i);
 }
 
 void HeMenubar::aboutCB(Fl_Widget*, void*) {
-  fl_message("mickey "MM_VERSION"\n"MM_COPYRIGHT"\n\n"
+  fl_message("mickey " MM_VERSION"\n" MM_COPYRIGHT"\n\n"
              "a free cross platform hex editor\n\n"
              MM_WEB);
 }
@@ -1683,7 +1683,7 @@ HeCycleButton::HeCycleButton(int x, int y, int w, int 
   box(FL_PLASTIC_UP_BOX);
   choice = 0; nChoice = n;
   warn = 0;
-  labels = new (char*)[n];
+  labels = new char*[n];
   labels[0] = t;
   va_list va;
   va_start(va, t);
