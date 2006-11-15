--- src/jrd/svc.cpp.orig	Mon Jul 31 11:43:28 2006
+++ src/jrd/svc.cpp	Wed Nov 15 16:56:13 2006
@@ -583,7 +583,8 @@
 	{
 #ifndef SERVICE_THREAD
 		TEXT service_path[MAXPATHLEN];
-		gds__prefix(service_path, serv->serv_executable);
+		strlcpy(service_path, FB_EXEC_PREFIX "/", MAXPATHLEN);
+		strlcat(service_path, serv->serv_executable, MAXPATHLEN);
 		service_fork(service_path, service);
 #else
 		/* if service is single threaded, only call if not currently running */
@@ -1742,7 +1743,8 @@
 	TEXT service_path[MAXPATHLEN];
 
 	if (serv->serv_executable) {
-		gds__prefix(service_path, serv->serv_executable);
+		strlcpy(service_path, FB_EXEC_PREFIX "/", MAXPATHLEN);
+		strlcat(service_path, serv->serv_executable, MAXPATHLEN);
 		service->svc_flags = SVC_forked;
 		service_fork(service_path, service);
 	}
