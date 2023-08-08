--- P4API.cpp.orig	2020-07-15 12:24:50 UTC
+++ P4API.cpp
@@ -337,7 +337,7 @@ static PyObject * P4API_dvcs_init(P4Adapter * self, Py
             return NULL;
 
 
-    auto_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
+    unique_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
 
     if( personalServer.get() == NULL)
 	return NULL;
@@ -399,7 +399,7 @@ static PyObject * P4API_dvcs_clone(P4Adapter * self, P
 					 &progress))
 	return NULL;
 
-    auto_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
+    unique_ptr<ServerHelperApi> personalServer( create_server(user, client, directory, &ui) );
 
     if( personalServer.get() == NULL)
 	return NULL;
