--- src/butil/details/extended_endpoint.hpp.orig	2026-02-23 02:11:29 UTC
+++ src/butil/details/extended_endpoint.hpp
@@ -163,7 +163,7 @@ class ExtendedEndPoint { (public)
                 eep->_u.in6.sin6_flowinfo = 0u;
                 eep->_u.in6.sin6_scope_id = 0u;
                 eep->_socklen = sizeof(_u.in6);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
                 eep->_u.in6.sin6_len = eep->_socklen;
 #endif
             }
@@ -177,7 +177,7 @@ class ExtendedEndPoint { (public)
                 int size = sp.copy(eep->_u.un.sun_path, sp.size());
                 eep->_u.un.sun_path[size] = '\0';
                 eep->_socklen = offsetof(sockaddr_un, sun_path) + size + 1;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
                 eep->_u.un.sun_len = eep->_socklen;
 #endif
             }
