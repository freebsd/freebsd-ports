--- Core/Reporting.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/Reporting.cpp
@@ -189,8 +189,6 @@ namespace Reporting
 		return "Mac";
 #elif defined(__SYMBIAN32__)
 		return "Symbian";
-#elif defined(__FreeBSD__)
-		return "BSD";
 #elif defined(BLACKBERRY)
 		return "Blackberry";
 #elif defined(LOONGSON)
@@ -199,6 +197,16 @@ namespace Reporting
 		return "Nokia Maemo";
 #elif defined(__linux__)
 		return "Linux";
+#elif defined(__Bitrig__)
+		return "Bitrig";
+#elif defined(__DragonFly__)
+		return "DragonFly";
+#elif defined(__FreeBSD__)
+		return "FreeBSD";
+#elif defined(__NetBSD__)
+		return "NetBSD";
+#elif defined(__OpenBSD__)
+		return "OpenBSD";
 #else
 		return "Unknown";
 #endif
