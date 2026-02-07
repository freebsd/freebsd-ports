--- source/host.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/host.cpp
@@ -523,7 +523,7 @@ void Host_Error(const char *error, ...)
 COMMAND(Version)
 {
 	GCon->Log("VAVOOM version " VERSION_TEXT" (r" SVN_REVISION_STRING ").");
-	GCon->Log("Compiled "__DATE__" "__TIME__".");
+	GCon->Log("Compiled " __DATE__ " " __TIME__ ".");
 }
 
 //==========================================================================
@@ -706,5 +706,5 @@ void Host_Shutdown()
 
 	SAFE_SHUTDOWN(VObject::StaticExit, ())
 	SAFE_SHUTDOWN(VName::StaticExit, ())
-	SAFE_SHUTDOWN(Z_Shutdown, ())
+//	SAFE_SHUTDOWN(Z_Shutdown, ())
 }
