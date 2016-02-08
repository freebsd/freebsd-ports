--- sal/osl/unx/sockimpl.hxx.orig	2015-12-11 02:29:35 UTC
+++ sal/osl/unx/sockimpl.hxx
@@ -24,11 +24,15 @@
 #include <osl/socket.h>
 #include <osl/interlck.h>
 
+#if defined(FREEBSD) || defined(LINUX)
+#define CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT 1
+#endif
+
 struct oslSocketImpl {
     int                 m_Socket;
     int                 m_nLastError;
     oslInterlockedCount m_nRefCount;
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     bool                m_bIsAccepting;
     bool                m_bIsInShutdown;
 #endif
@@ -45,7 +49,7 @@ struct oslPipeImpl {
     sal_Char m_Name[PATH_MAX + 1];
     oslInterlockedCount m_nRefCount;
     bool m_bClosed;
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     bool m_bIsAccepting;
     bool m_bIsInShutdown;
 #endif
