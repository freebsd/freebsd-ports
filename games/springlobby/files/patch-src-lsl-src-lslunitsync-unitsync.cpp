--- src/lsl/src/lslunitsync/unitsync.cpp.orig	2013-11-23 01:34:07.000000000 +0400
+++ src/lsl/src/lslunitsync/unitsync.cpp	2013-12-10 04:23:40.875093997 +0400
@@ -55,13 +55,7 @@
 {
 	static std::locale l("C");
 	static boost::is_iless il(l);
-	try {
-		//this fails on certain names
-		return il(first,second);
-	}
-	catch(...) {
-		return first < second;
-	}
+	return first < second;
 }
 
 bool Unitsync::LoadUnitSyncLib( const std::string& unitsyncloc )
