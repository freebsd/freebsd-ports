Set DATADIR url to Help pages

--- gui-wx/wxhelp.cpp.orig	2025-07-07 22:49:26 UTC
+++ gui-wx/wxhelp.cpp
@@ -177,7 +177,7 @@ long whenactive;              // when help window beca
 
 long whenactive;              // when help window became active (elapsed millisecs)
 
-const wxString helphome = _("Help/index.html");    // contents page
+const wxString helphome = _("%%DATADIR%%/Help/index.html");    // contents page
 wxString currhelp = helphome;                      // current help file
 const wxString lexicon_name = _("lexicon");        // name of lexicon layer
 
@@ -1338,7 +1338,7 @@ void ShowAboutBox()
 #ifdef __WXMAC__
     html->SetFontSizes(13); // must be a fixed size (not helpfontsize)
 #endif
-    html->CheckAndLoad(_("Help/about.html"));
+    html->CheckAndLoad(_("%%DATADIR%%/Help/about.html"));
     
     // avoid HtmlView::OnSize calling CheckAndLoad again
     html->canreload = false;
