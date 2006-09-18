--- src/jrd/svc.cpp.orig	Tue Aug 15 23:06:16 2006
+++ src/jrd/svc.cpp	Tue Aug 15 23:06:50 2006
@@ -1742,8 +1742,8 @@
 	TEXT service_path[MAXPATHLEN];
 
 	if (serv->serv_executable) {
-		gds__prefix(service_path, serv->serv_executable);
-		service->svc_flags = SVC_forked;
+		strlcpy(service_path, FB_EXEC_PREFIX "/", MAXPATHLEN);
+		strlcat(service_path, serv->serv_executable, MAXPATHLEN);
 		service_fork(service_path, service);
 	}
 
