--- sal/osl/unx/pipe.cxx.orig	2015-12-11 02:29:35 UTC
+++ sal/osl/unx/pipe.cxx
@@ -82,10 +82,10 @@ oslPipe __osl_createPipeImpl()
         return NULL;
     pPipeImpl->m_nRefCount =1;
     pPipeImpl->m_bClosed = false;
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pPipeImpl->m_bIsInShutdown = false;
     pPipeImpl->m_bIsAccepting = false;
-#endif
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
     return pPipeImpl;
 }
 
@@ -359,7 +359,7 @@ void SAL_CALL osl_closePipe( oslPipe pPi
       Thread does not return from accept on linux, so
       connect to the accepting pipe
      */
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     struct sockaddr_un addr;
 
     if ( pPipe->m_bIsAccepting )
@@ -387,7 +387,7 @@ void SAL_CALL osl_closePipe( oslPipe pPi
         }
         close(fd);
     }
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
 
     nRet = shutdown(ConnFD, 2);
     if ( nRet < 0 )
@@ -421,13 +421,13 @@ oslPipe SAL_CALL osl_acceptPipe(oslPipe 
 
     OSL_ASSERT(strlen(pPipe->m_Name) > 0);
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pPipe->m_bIsAccepting = true;
 #endif
 
     s = accept(pPipe->m_Socket, NULL, NULL);
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     pPipe->m_bIsAccepting = false;
 #endif
 
@@ -437,13 +437,13 @@ oslPipe SAL_CALL osl_acceptPipe(oslPipe 
         return NULL;
     }
 
-#if defined(LINUX)
+#if CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT
     if ( pPipe->m_bIsInShutdown  )
     {
         close(s);
         return NULL;
     }
-#endif /* LINUX */
+#endif /* CLOSESOCKET_DOESNT_WAKE_UP_ACCEPT */
     else
     {
         /* alloc memory */
