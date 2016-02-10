--- sal/osl/unx/socket.cxx.orig	2015-12-11 02:29:35 UTC
+++ sal/osl/unx/socket.cxx
@@ -447,7 +447,7 @@ oslSocket __osl_createSocketImpl(int Soc
     pSocket->m_nLastError = 0;
     pSocket->m_nRefCount = 1;
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pSocket->m_bIsAccepting = false;
 #endif
 
@@ -1364,13 +1364,13 @@ void SAL_CALL osl_releaseSocket( oslSock
 {
     if( pSocket && 0 == osl_atomic_decrement( &(pSocket->m_nRefCount) ) )
     {
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     if ( pSocket->m_bIsAccepting )
     {
         SAL_WARN( "sal.osl", "attempt to destroy socket while accepting" );
         return;
     }
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
         osl_closeSocket( pSocket );
         __osl_destroySocketImpl( pSocket );
     }
@@ -1393,7 +1393,7 @@ void SAL_CALL osl_closeSocket(oslSocket 
 
     pSocket->m_Socket = OSL_INVALID_SOCKET;
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pSocket->m_bIsInShutdown = true;
 
     if ( pSocket->m_bIsAccepting )
@@ -1437,7 +1437,7 @@ void SAL_CALL osl_closeSocket(oslSocket 
         }
         pSocket->m_bIsAccepting = false;
     }
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
 
     nRet=close(nFD);
     if ( nRet != 0 )
@@ -1695,9 +1695,9 @@ oslSocket SAL_CALL osl_acceptConnectionO
     }
 
     pSocket->m_nLastError=0;
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pSocket->m_bIsAccepting = true;
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
 
     if( ppAddr && *ppAddr )
     {
@@ -1718,22 +1718,22 @@ oslSocket SAL_CALL osl_acceptConnectionO
         int nErrno = errno;
         SAL_WARN( "sal.osl", "accept connection failed: (" << nErrno << ") " << strerror(nErrno) );
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
         pSocket->m_bIsAccepting = false;
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
         return 0;
     }
 
     assert(AddrLen == sizeof(struct sockaddr));
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     if ( pSocket->m_bIsInShutdown )
     {
         close(Connection);
         SAL_WARN( "sal.osl", "close while accept" );
         return 0;
     }
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
 
     if(ppAddr)
     {
@@ -1758,11 +1758,11 @@ oslSocket SAL_CALL osl_acceptConnectionO
 
     pConnectionSockImpl->m_Socket           = Connection;
     pConnectionSockImpl->m_nLastError       = 0;
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pConnectionSockImpl->m_bIsAccepting     = false;
 
     pSocket->m_bIsAccepting = false;
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
     return pConnectionSockImpl;
 }
 
