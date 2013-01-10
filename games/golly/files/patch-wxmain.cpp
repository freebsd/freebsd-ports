--- ./wxmain.cpp.orig	2012-06-29 21:55:00.000000000 +0000
+++ ./wxmain.cpp	2012-12-31 11:54:05.974993147 +0000
@@ -933,7 +933,7 @@
       treectrl->Expand(id);
       
       // nicer to expand Perl & Python subdirs inside Scripts
-      if ( dir == gollydir + _("Scripts") ) {
+      if ( dir == wxString(DATADIR) + _("Scripts") ) {
          wxTreeItemId child;
          wxTreeItemIdValue cookie;
          child = treectrl->GetFirstChild(id, cookie);
