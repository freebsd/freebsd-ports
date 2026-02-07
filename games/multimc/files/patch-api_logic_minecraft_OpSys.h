--- api/logic/minecraft/OpSys.h.orig	2019-03-09 16:25:37 UTC
+++ api/logic/minecraft/OpSys.h
@@ -18,6 +18,7 @@
 enum OpSys
 {
     Os_Windows,
+	Os_FreeBSD,
     Os_Linux,
     Os_OSX,
     Os_Other
@@ -28,10 +29,10 @@ QString OpSys_toString(OpSys);
 
 #ifdef Q_OS_WIN32
 #define currentSystem Os_Windows
-#else
-#ifdef Q_OS_MAC
+#elif Q_OS_MAC
 #define currentSystem Os_OSX
+#elif defined Q_OS_FREEBSD
+#define currentSystem Os_FreeBSD
 #else
 #define currentSystem Os_Linux
-#endif
-#endif
\ No newline at end of file
+#endif
