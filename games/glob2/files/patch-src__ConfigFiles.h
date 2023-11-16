--- src/ConfigFiles.h.orig	2023-06-13 07:14:47 UTC
+++ src/ConfigFiles.h
@@ -178,7 +178,11 @@ class ConfigVector (public)
 		else
 		{
 			std::cerr << "ConfigVector::get(" << static_cast<unsigned int>(id) << ") : warning : id is not valid, returning default" << std::endl;
-			assert(false);
+			// FreeBSD: patch impoted from glob2's CVS
+			//			assert(false);
+			// I commented the assert because it crashed glob2
+			// sometimes, when a building was repaired.
+			// This has to be really fixed!
 			return &defaultEntry;
 		}
 	}
