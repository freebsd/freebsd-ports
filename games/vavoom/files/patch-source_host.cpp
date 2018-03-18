--- source/host.cpp.orig	2018-03-18 07:16:51.331022000 +0100
+++ source/host.cpp	2018-03-18 07:17:13.897333000 +0100
@@ -523,7 +523,7 @@
 COMMAND(Version)
 {
 	GCon->Log("VAVOOM version " VERSION_TEXT" (r" SVN_REVISION_STRING ").");
-	GCon->Log("Compiled "__DATE__" "__TIME__".");
+	GCon->Log("Compiled " __DATE__ " " __TIME__ ".");
 }
 
 //==========================================================================
@@ -706,5 +706,5 @@
 
 	SAFE_SHUTDOWN(VObject::StaticExit, ())
 	SAFE_SHUTDOWN(VName::StaticExit, ())
-	SAFE_SHUTDOWN(Z_Shutdown, ())
+//	SAFE_SHUTDOWN(Z_Shutdown, ())
 }
