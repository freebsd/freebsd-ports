--- base/src/player.cpp.orig	Sun Aug  3 04:17:48 2003
+++ base/src/player.cpp	Thu Aug 21 21:50:28 2003
@@ -708,7 +708,7 @@
 #ifndef HAVE_GTK
       if (name == "zinf.ui") {
           pref = kTextUIPref;
-          context->prefs->GetPrefString(pref, name);
+          m_context->prefs->GetPrefString(pref, name);
       }
 #endif
 #endif
@@ -869,7 +869,7 @@
 //         cerr << boost::format("%1% will quit") % The_BRANDING << endl;
 
 
-         cerr << "No UI plugin in '" << thePath << "' matched 'plugins/" << name << "' or 'plugins/" << name << ".ui.'" << endl;
+         cerr << "If this was the first time you started zinf just try again." << endl;
          cerr << The_BRANDING << " will quit." << endl;
 #endif
          Event    *e = new Event(CMD_QuitPlayer);
