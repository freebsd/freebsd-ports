--- P4API.cpp.orig	2024-12-28 20:29:18 UTC
+++ P4API.cpp
@@ -338,7 +338,7 @@ static PyObject * P4API_dvcs_init(P4Adapter * self, Py
             return NULL;
 
 
-    auto_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
+    unique_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
 
     if( personalServer.get() == NULL)
 	return NULL;
@@ -400,7 +400,7 @@ static PyObject * P4API_dvcs_clone(P4Adapter * self, P
 					 &progress))
 	return NULL;
 
-    auto_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
+    unique_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
 
     if( personalServer.get() == NULL)
 	return NULL;
