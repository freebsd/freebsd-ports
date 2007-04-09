--- src/ConfigFiles.h.orig	Sat Sep  9 16:07:13 2006
+++ src/ConfigFiles.h	Sun Apr  8 18:55:00 2007
@@ -178,7 +178,11 @@
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
