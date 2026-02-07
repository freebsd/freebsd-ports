--- src/fxasq.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/fxasq.cpp
@@ -133,7 +133,7 @@ int FxAsqWin::Run(FxAsqItem**results)
   dlg->create();
   dlg->setWidth(dlg->getDefaultWidth());
   dlg->setHeight(dlg->getDefaultHeight());
-  for (FXint i=keylist.first(); i<=keylist.last(); i=keylist.next(i))
+  if (UsedSlotsInDict(&keylist)>0) for (FXint i=0; i<TotalSlotsInDict(&keylist); ++i)
   {
     focused_btn=-1; // Focusing a button doesn't make much sense for interactive dialogs.
     FXWindow*obj=(FXWindow*)(keylist.data(i));
@@ -186,8 +186,8 @@ int FxAsqWin::Run(FxAsqItem**results)
 
 void FxAsqWin::PutResults()
 {
-  for (FXint i=keylist.first(); i<=keylist.last(); i=keylist.next(i)) {
-    const char*k=keylist.key(i);
+  for (FXint i=0; i<TotalSlotsInDict(&keylist); ++i) {
+    const char*k=DictKeyName(keylist,i);
     FXWindow*obj=(FXWindow*)keylist.data(i);
     if (k&&obj) {
       if (IsGroup(obj)) {
@@ -299,7 +299,7 @@ void FxAsqWin::Select(const char*key, const char*value
 {
   FXHorizontalFrame *frm = new FXHorizontalFrame(userbox,LAYOUT_FILL_X);
   new FXLabel(frm,label,NULL);
-  FXListBox*list=(FXListBox*)(keylist.find(key));
+  FXListBox*list=(FXListBox*)(LookupInDict(&keylist,key));
   if (list) {
     list->reparent(frm);
     void*p=list->getUserData();
@@ -315,7 +315,7 @@ void FxAsqWin::Select(const char*key, const char*value
 
 void FxAsqWin::Option(const char*key, const char*value, const char*label)
 {
-  FXListBox*list=(FXListBox*)(keylist.find(key));
+  FXListBox*list=(FXListBox*)(LookupInDict(&keylist,key));
   if (!IsList(list)) {
     list=new FXListBox(userbox,NULL,0,LISTBOX_OPTS);
     keylist.insert(key,list);
@@ -327,7 +327,7 @@ void FxAsqWin::Option(const char*key, const char*value
 
 void FxAsqWin::Group(const char*key, const char*value, const char*label)
 {
-  GroupBox*grp=(GroupBox*)(keylist.find(key));
+  GroupBox*grp=(GroupBox*)(LookupInDict(&keylist,key));
   if (grp) {
     ((FXWindow*)grp)->reparent(userbox);
     grp->setText(label);
@@ -341,7 +341,7 @@ void FxAsqWin::Group(const char*key, const char*value,
 
 void FxAsqWin::Radio(const char*key, const char*value, const char*label)
 {
-  GroupBox*grp=(GroupBox*)(keylist.find(key));
+  GroupBox*grp=(GroupBox*)(LookupInDict(&keylist,key));
   if (!IsGroup(grp)) {
     grp=new GroupBox(userbox,NULL);
     keylist.insert(key,grp);
@@ -505,7 +505,7 @@ void FxAsqWin::Font(const char*key, const char*value, 
 FxAsqWin::~FxAsqWin()
 {
   void*p=NULL;
-  for (FXint i=keylist.first(); i<=keylist.last(); i=keylist.next(i)) {
+  for (FXint i=0; i<TotalSlotsInDict(&keylist); ++i) {
     FXWindow*obj=(FXWindow*)(keylist.data(i));
     if (IsList(obj)) {
       FXListBox*listbox=(FXListBox*)obj;
