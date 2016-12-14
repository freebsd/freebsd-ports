commit 280cd523686fbdb175d50417266d2487a8ce67d2
Author: Florent Rougon <f.rougon@free.fr>
Date:   Fri Dec 9 11:29:13 2016 +0100

    Security fix: don't allow the route manager to overwrite any file
    
    Since the Save function can be triggered from Nasal with an arbitrary
    path, we must check this path before overwriting the file.
    
    (also add a missing include that is directly needed for this commit)

diff --git src/Autopilot/route_mgr.cxx src/Autopilot/route_mgr.cxx
index bae5b1d23..901c64e14 100644
--- src/Autopilot/route_mgr.cxx
+++ src/Autopilot/route_mgr.cxx
@@ -44,6 +44,7 @@
 #include <simgear/timing/sg_time.hxx>
 #include <simgear/sg_inlines.h>
 
+#include <Main/globals.hxx>
 #include "Main/fg_props.hxx"
 #include "Navaids/positioned.hxx"
 #include <Navaids/waypoint.hxx>
@@ -54,6 +55,8 @@
 #include "Airports/runways.hxx"
 #include <GUI/new_gui.hxx>
 #include <GUI/dialog.hxx>
+#include <Main/util.hxx>        // fgValidatePath()
+#include <GUI/MessageBox.hxx>
 
 #define RM "/autopilot/route-manager/"
 
@@ -709,7 +712,21 @@ void FGRouteMgr::InputListener::valueChanged(SGPropertyNode *prop)
       mgr->loadRoute(path);
     } else if (!strcmp(s, "@SAVE")) {
       SGPath path(mgr->_pathNode->getStringValue());
-      mgr->saveRoute(path);
+      SGPath authorizedPath = fgValidatePath(path, true /* write */);
+
+      if (!authorizedPath.isNull()) {
+        mgr->saveRoute(authorizedPath);
+      } else {
+        std::string msg =
+          "The route manager was asked to write the flightplan to '" +
+          path.utf8Str() + "', but this path is not authorized for writing. " +
+          "Please choose another location, for instance in the $FG_HOME/Export "
+          "folder (" + (globals->get_fg_home() / "Export").utf8Str() + ").";
+
+        SG_LOG(SG_AUTOPILOT, SG_ALERT, msg);
+        modalMessageBox("FlightGear", "Unable to write to the specified file",
+                        msg);
+      }
     } else if (!strcmp(s, "@NEXT")) {
       mgr->jumpToIndex(mgr->currentIndex() + 1);
     } else if (!strcmp(s, "@PREVIOUS")) {
