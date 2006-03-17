--- src/jrd/svc.cpp.orig	Tue Jan 24 17:11:48 2006
+++ src/jrd/svc.cpp	Tue Jan 24 17:27:22 2006
@@ -1902,7 +1902,8 @@
 
 #ifndef SUPERSERVER
 	if (serv->serv_executable) {
-		gds__prefix(service_path, serv->serv_executable);
+		strlcpy(service_path, FB_EXEC_PREFIX "/", MAXPATHLEN);
+		strlcat(service_path, serv->serv_executable, MAXPATHLEN);
 		service->svc_flags = SVC_forked;
 		service_fork(service_path, service);
 	}
