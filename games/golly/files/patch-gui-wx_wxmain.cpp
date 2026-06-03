Set DATADIR url to Help pages

--- gui-wx/wxmain.cpp.orig	2025-09-26 02:31:41 UTC
+++ gui-wx/wxmain.cpp
@@ -1410,29 +1410,29 @@ void MainFrame::OnMenu(wxCommandEvent& event)
         case ID_TILE:           ToggleTileLayers(); break;
             
         // Help menu
-        case ID_HELP_INDEX:     ShowHelp(_("Help/index.html")); break;
-        case ID_HELP_INTRO:     ShowHelp(_("Help/intro.html")); break;
-        case ID_HELP_TIPS:      ShowHelp(_("Help/tips.html")); break;
-        case ID_HELP_ALGOS:     ShowHelp(_("Help/algos.html")); break;
-        case ID_HELP_LEXICON:   ShowHelp(_("Help/Lexicon/lex.htm")); break;
-        case ID_HELP_ARCHIVES:  ShowHelp(_("Help/archives.html")); break;
-        case ID_HELP_LUA:       ShowHelp(_("Help/lua.html")); break;
-        case ID_HELP_OVERLAY:   ShowHelp(_("Help/overlay.html")); break;
-        case ID_HELP_PYTHON:    ShowHelp(_("Help/python.html")); break;
+        case ID_HELP_INDEX:     ShowHelp(_("%%DATADIR%%/Help/index.html")); break;
+        case ID_HELP_INTRO:     ShowHelp(_("%%DATADIR%%/Help/intro.html")); break;
+        case ID_HELP_TIPS:      ShowHelp(_("%%DATADIR%%/Help/tips.html")); break;
+        case ID_HELP_ALGOS:     ShowHelp(_("%%DATADIR%%/Help/algos.html")); break;
+        case ID_HELP_LEXICON:   ShowHelp(_("%%DATADIR%%/Help/Lexicon/lex.htm")); break;
+        case ID_HELP_ARCHIVES:  ShowHelp(_("%%DATADIR%%/Help/archives.html")); break;
+        case ID_HELP_LUA:       ShowHelp(_("%%DATADIR%%/Help/lua.html")); break;
+        case ID_HELP_OVERLAY:   ShowHelp(_("%%DATADIR%%/Help/overlay.html")); break;
+        case ID_HELP_PYTHON:    ShowHelp(_("%%DATADIR%%/Help/python.html")); break;
         case ID_HELP_KEYBOARD:  ShowHelp(SHOW_KEYBOARD_SHORTCUTS); break;
-        case ID_HELP_MOUSE:     ShowHelp(_("Help/mouse.html")); break;
-        case ID_HELP_FILE:      ShowHelp(_("Help/file.html")); break;
-        case ID_HELP_EDIT:      ShowHelp(_("Help/edit.html")); break;
-        case ID_HELP_CONTROL:   ShowHelp(_("Help/control.html")); break;
-        case ID_HELP_VIEW:      ShowHelp(_("Help/view.html")); break;
-        case ID_HELP_LAYER:     ShowHelp(_("Help/layer.html")); break;
-        case ID_HELP_HELP:      ShowHelp(_("Help/help.html")); break;
-        case ID_HELP_REFS:      ShowHelp(_("Help/refs.html")); break;
-        case ID_HELP_FORMATS:   ShowHelp(_("Help/formats.html")); break;
-        case ID_HELP_BOUNDED:   ShowHelp(_("Help/bounded.html")); break;
-        case ID_HELP_PROBLEMS:  ShowHelp(_("Help/problems.html")); break;
-        case ID_HELP_CHANGES:   ShowHelp(_("Help/changes.html")); break;
-        case ID_HELP_CREDITS:   ShowHelp(_("Help/credits.html")); break;
+        case ID_HELP_MOUSE:     ShowHelp(_("%%DATADIR%%/Help/mouse.html")); break;
+        case ID_HELP_FILE:      ShowHelp(_("%%DATADIR%%/Help/file.html")); break;
+        case ID_HELP_EDIT:      ShowHelp(_("%%DATADIR%%/Help/edit.html")); break;
+        case ID_HELP_CONTROL:   ShowHelp(_("%%DATADIR%%/Help/control.html")); break;
+        case ID_HELP_VIEW:      ShowHelp(_("%%DATADIR%%/Help/view.html")); break;
+        case ID_HELP_LAYER:     ShowHelp(_("%%DATADIR%%/Help/layer.html")); break;
+        case ID_HELP_HELP:      ShowHelp(_("%%DATADIR%%/Help/help.html")); break;
+        case ID_HELP_REFS:      ShowHelp(_("%%DATADIR%%/Help/refs.html")); break;
+        case ID_HELP_FORMATS:   ShowHelp(_("%%DATADIR%%/Help/formats.html")); break;
+        case ID_HELP_BOUNDED:   ShowHelp(_("%%DATADIR%%/Help/bounded.html")); break;
+        case ID_HELP_PROBLEMS:  ShowHelp(_("%%DATADIR%%/Help/problems.html")); break;
+        case ID_HELP_CHANGES:   ShowHelp(_("%%DATADIR%%/Help/changes.html")); break;
+        case ID_HELP_CREDITS:   ShowHelp(_("%%DATADIR%%/Help/credits.html")); break;
         case ID_HELP_BUTT:      ShowHelp(wxEmptyString); break;
         case wxID_ABOUT:        ShowAboutBox(); break;
             
