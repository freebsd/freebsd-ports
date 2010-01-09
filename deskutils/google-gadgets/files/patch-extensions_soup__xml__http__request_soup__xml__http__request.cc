
$FreeBSD$

--- extensions/soup_xml_http_request/soup_xml_http_request.cc.orig
+++ extensions/soup_xml_http_request/soup_xml_http_request.cc
@@ -1004,7 +1004,7 @@
            it != sessions_.end(); ++it) {
         g_object_set(G_OBJECT(it->second),
                      SOUP_SESSION_USER_AGENT, default_user_agent_.c_str(),
-                     NULL);
+                     (const gchar*)0);
       }
     }
   }
@@ -1016,7 +1016,7 @@
 #ifdef HAVE_LIBSOUP_GNOME
         SOUP_SESSION_ADD_FEATURE_BY_TYPE, SOUP_TYPE_PROXY_RESOLVER_GNOME,
 #endif
-        NULL);
+        (const char*)0);
 
     if (session) {
 #ifdef SOUP_XHR_VERBOSE
@@ -1031,7 +1031,7 @@
 #ifdef GGL_DEFAULT_SSL_CA_FILE
                    SOUP_SESSION_SSL_CA_FILE, GGL_DEFAULT_SSL_CA_FILE,
 #endif
-                   NULL);
+                   (const gchar*)0);
 
       g_signal_connect(G_OBJECT(session), "authenticate",
                        G_CALLBACK(AuthenticateCallback), this);
