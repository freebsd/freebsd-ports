--- api/logic/minecraft/OpSys.h.orig	2017-12-18 00:19:43 UTC
+++ api/logic/minecraft/OpSys.h
@@ -20,6 +20,7 @@ enum OpSys
 	Os_Windows,
 	Os_Linux,
 	Os_OSX,
+	Os_FreeBSD,
 	Os_Other
 };
 
@@ -28,10 +29,10 @@ QString OpSys_toString(OpSys);
 
 #ifdef Q_OS_WIN32
 #define currentSystem Os_Windows
-#else
-#ifdef Q_OS_MAC
+#elif defined Q_OS_MAC
 #define currentSystem Os_OSX
+#elif defined Q_OS_FREEBSD
+#define currentSystem Os_FreeBSD
 #else
 #define currentSystem Os_Linux
 #endif
-#endif
\ No newline at end of file
