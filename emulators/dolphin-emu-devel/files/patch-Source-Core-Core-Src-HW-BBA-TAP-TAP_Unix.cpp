--- Source/Core/Core/Src/HW/BBA-TAP/TAP_Unix.cpp.orig	2012-09-12 15:47:40.000000000 +0200
+++ Source/Core/Core/Src/HW/BBA-TAP/TAP_Unix.cpp	2012-09-12 15:52:09.000000000 +0200
@@ -119,6 +119,7 @@
 #endif
 }
 
+#ifdef __linux__
 void ReadThreadHandler(CEXIETHERNET* self)
 {
 	while (true)
@@ -149,6 +150,7 @@
 		}
 	}
 }
+#endif
 
 bool CEXIETHERNET::RecvInit()
 {
