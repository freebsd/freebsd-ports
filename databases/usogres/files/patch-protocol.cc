--- src/protocol.cc.orig	Wed Aug 20 19:10:01 2003
+++ src/protocol.cc	Wed Aug 20 19:10:03 2003
@@ -330,7 +330,7 @@
 #ifdef WIN32
 			std::string str(p + sizeof(int), len);
 #else
-			string str(p + sizeof(int), len);
+			std::string str(p + sizeof(int), len);
 #endif
 			printf("   Value:%s\n", str.c_str());
 			p += len + sizeof(int);
