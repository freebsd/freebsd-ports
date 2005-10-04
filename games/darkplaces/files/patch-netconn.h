--- netconn.h.orig	Thu Aug 18 21:30:57 2005
+++ netconn.h	Thu Aug 25 19:20:34 2005
@@ -251,7 +251,7 @@
 
 extern qboolean serverlist_consoleoutput;
 
-#if !defined(_WIN32) && !defined(__linux__) && !defined(SUNOS)
+#if !defined(_WIN32) && !defined(__linux__) && !defined(SUNOS) && !defined(__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
