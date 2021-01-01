--- ./src/ConfigFiles.h.orig	2009-06-14 12:11:34.000000000 +0200
+++ ./src/ConfigFiles.h	2013-10-28 01:26:26.000000000 +0100
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
