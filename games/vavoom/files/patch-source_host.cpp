--- source/host.cpp.orig	2017-06-04 12:56:34.440473000 +0200
+++ source/host.cpp	2017-06-04 13:10:16.524114000 +0200
@@ -706,5 +706,5 @@
 
 	SAFE_SHUTDOWN(VObject::StaticExit, ())
 	SAFE_SHUTDOWN(VName::StaticExit, ())
-	SAFE_SHUTDOWN(Z_Shutdown, ())
+//	SAFE_SHUTDOWN(Z_Shutdown, ())
 }
