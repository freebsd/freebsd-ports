--- src/prefdlg.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/prefdlg.cpp
@@ -415,13 +415,13 @@ void PrefsDialog::MakeGeneralTab()
   right_column=new FXVerticalFrame(hframe,FRAME_SUNKEN|LAYOUT_FILL/*|PACK_UNIFORM_HEIGHT*/);
 
   chk=new FXCheckButton(left_column, _("Watch files for external changes."), prefs, Settings::ID_TOGGLE_WATCH_EXTERN);
-  chk->setCheck(prefs->WatchExternChanges, FALSE);
+  chk->setCheck(prefs->WatchExternChanges, false);
   chk->setPadBottom(8);
 
   hframe=new FXHorizontalFrame(left_column);
   SetPad(hframe,0);
   chk=new FXCheckButton(hframe, _("Backup files every "), prefs, Settings::ID_TOGGLE_AUTOSAVE);
-  chk->setCheck(prefs->Autosave, FALSE);
+  chk->setCheck(prefs->Autosave, false);
   chk->setPadBottom(12);
   spin=new FXSpinner(hframe, 3, prefs, Settings::ID_SET_AUTOSAVE_INT,SPIN_OPTS);
   spin->setRange(15,900);
@@ -433,10 +433,10 @@ void PrefsDialog::MakeGeneralTab()
 
   new FXLabel(left_column,  _("Ask before closing multiple files:"));
   chk=new FXCheckButton(left_column, _("From menu"), prefs, Settings::ID_TOGGLE_ASK_CLOSE_MULTI_MENU);
-  chk->setCheck(prefs->PromptCloseMultiMenu, FALSE);
+  chk->setCheck(prefs->PromptCloseMultiMenu, false);
   chk->setPadLeft(12);
   chk=new FXCheckButton(left_column, _("On exit"), prefs, Settings::ID_TOGGLE_ASK_CLOSE_MULTI_EXIT);
-  chk->setCheck(prefs->PromptCloseMultiExit, FALSE);
+  chk->setCheck(prefs->PromptCloseMultiExit, false);
   chk->setPadLeft(12);
   chk->setPadBottom(12);
 
@@ -464,15 +464,15 @@ void PrefsDialog::MakeGeneralTab()
 
   new FXLabel(right_column,_("Save open files before executing:"));
   chk=new FXCheckButton(right_column, _("Tools->Filter Selection"), prefs, Settings::ID_SAVE_ON_FILTER_SEL);
-  chk->setCheck(prefs->SaveBeforeFilterSel, FALSE);
+  chk->setCheck(prefs->SaveBeforeFilterSel, false);
   chk->setPadLeft(12);
 
   chk=new FXCheckButton(right_column, _("Tools->Insert Command"), prefs, Settings::ID_SAVE_ON_INS_CMD);
-  chk->setCheck(prefs->SaveBeforeInsCmd, FALSE);
+  chk->setCheck(prefs->SaveBeforeInsCmd, false);
   chk->setPadLeft(12);
 
   chk=new FXCheckButton(right_column, _("Tools->Execute Command"), prefs, Settings::ID_SAVE_ON_EXEC_CMD);
-  chk->setCheck(prefs->SaveBeforeExecCmd, FALSE);
+  chk->setCheck(prefs->SaveBeforeExecCmd, false);
   chk->setPadLeft(12);
 
 #ifndef WIN32
@@ -539,19 +539,19 @@ void PrefsDialog::MakeEditorTab()
   list->setCurrentItem(prefs->AutoIndent);
 
   chk=new FXCheckButton(column, _("Smart home key"), prefs, Settings::ID_TOGGLE_SMART_HOME);
-  chk->setCheck(prefs->SmartHome, FALSE);
+  chk->setCheck(prefs->SmartHome, false);
 
   chk=new FXCheckButton(column, _("Smooth scrolling"), prefs, Settings::ID_TOGGLE_SMOOTH_SCROLL);
-  chk->setCheck(prefs->SmoothScroll, FALSE);
+  chk->setCheck(prefs->SmoothScroll, false);
 
   chk=new FXCheckButton(column, _("Allow caret beyond end of line"), prefs, Settings::ID_TOGGLE_CARET_PAST_EOL);
-  chk->setCheck(prefs->CaretPastEOL, FALSE);
+  chk->setCheck(prefs->CaretPastEOL, false);
 
   chk=new FXCheckButton(column,_("Turn line wrapping on by default"),prefs,Settings::ID_TOGGLE_WORD_WRAP);
   chk->setCheck(prefs->WordWrap);
 
   chk=new FXCheckButton(column, _("Wrap-aware home/end keys"), prefs, Settings::ID_TOGGLE_WRAP_AWARE);
-  chk->setCheck(prefs->WrapAwareHomeEnd, FALSE);
+  chk->setCheck(prefs->WrapAwareHomeEnd, false);
 
   spinframe=new FXHorizontalFrame(column);
   spin=new FXSpinner(spinframe, 2, prefs, Settings::ID_SET_CARET_WIDTH, SPIN_OPTS);
@@ -605,14 +605,14 @@ void PrefsDialog::MakeEditorTab()
   new FXLabel(spinframe, _("Indent width"));
 
   chk->setUserData((void*)spin);
-  chk->setCheck(prefs->UseTabs, TRUE);
+  chk->setCheck(prefs->UseTabs, true);
 
   new FXHorizontalSeparator(column,LAYOUT_SIDE_TOP|LAYOUT_FILL_X|SEPARATOR_GROOVE);
   new FXLabel(column, _("Default search options:"));
   srchopts=new SciSearchOptions(column, prefs,Settings::ID_SET_SEARCH_OPTS);
   srchopts->SetSciFlags(prefs->SearchOptions);
   chk=new FXCheckButton(column, _("Verbose search messages"), prefs, Settings::ID_TOGGLE_SEARCH_VERBOSE);
-  chk->setCheck(prefs->SearchVerbose, FALSE);
+  chk->setCheck(prefs->SearchVerbose, false);
   chk->setPadLeft(6);
 
   spinframe=new FXHorizontalFrame(column);
@@ -635,10 +635,10 @@ void PrefsDialog::MakeEditorTab()
 
   new FXHorizontalSeparator(column,LAYOUT_SIDE_TOP|LAYOUT_FILL_X|SEPARATOR_GROOVE);
   chk=new FXCheckButton(column, _("Open 7-bit ASCII files as UTF-8"), prefs, Settings::ID_TOGGLE_ASCII_DEFAULT);
-  chk->setCheck(!prefs->DefaultToAscii, FALSE);
+  chk->setCheck(!prefs->DefaultToAscii, false);
   chk->setPadBottom(4);
   chk=new FXCheckButton(column, _("Treat other files as broken UTF-8"), prefs, Settings::ID_TOGGLE_SBCS_DEFAULT);
-  chk->setCheck(!prefs->DefaultToSbcs, FALSE);
+  chk->setCheck(!prefs->DefaultToSbcs, false);
   chk->setPadBottom(8);
   spinframe=new FXHorizontalFrame(column);
   new FXLabel(spinframe, _("Default file format:"));
@@ -651,7 +651,7 @@ void PrefsDialog::MakeEditorTab()
 
   chk=new FXCheckButton(column, _("Show line endings with \"View Whitespace\""),
                           prefs, Settings::ID_TOGGLE_VIEW_WHITESPACE_EOL);
-  chk->setCheck(prefs->WhitespaceShowsEOL, FALSE);
+  chk->setCheck(prefs->WhitespaceShowsEOL, false);
   chk->setPadLeft(6);
 }
 
