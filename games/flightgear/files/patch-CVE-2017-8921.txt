Fix for CVE-2017-8921 (backport of commit faf872e7)

--- src/Autopilot/route_mgr.cxx.orig
+++ src/Autopilot/route_mgr.cxx
@@ -74,7 +74,22 @@ static bool commandSaveFlightPlan(const SGPropertyNode* arg)
 {
   FGRouteMgr* self = (FGRouteMgr*) globals->get_subsystem("route-manager");
   SGPath path = SGPath::fromUtf8(arg->getStringValue("path"));
-  return self->saveRoute(path);
+  SGPath authorizedPath = fgValidatePath(path, true /* write */);
+
+  if (!authorizedPath.isNull()) {
+    return self->saveRoute(authorizedPath);
+  } else {
+    std::string msg =
+          "The route manager was asked to write the flightplan to '" +
+          path.utf8Str() + "', but this path is not authorized for writing. " +
+          "Please choose another location, for instance in the $FG_HOME/Export "
+          "folder (" + (globals->get_fg_home() / "Export").utf8Str() + ").";
+
+    SG_LOG(SG_AUTOPILOT, SG_ALERT, msg);
+    modalMessageBox("FlightGear", "Unable to write to the specified file",
+                        msg);
+    return false;
+  }
 }
 
 static bool commandActivateFlightPlan(const SGPropertyNode* arg)
