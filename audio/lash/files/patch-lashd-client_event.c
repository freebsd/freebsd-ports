--- lashd/client_event.c.orig	2007-09-17 19:10:14.000000000 +0200
+++ lashd/client_event.c	2007-09-17 19:10:50.000000000 +0200
@@ -185,6 +185,7 @@
 		project_set_name(project, name);
 	}
 
+#if 0
 	err = gethostname(server_name, MAXHOSTNAMELEN);
 	if (err == -1) {
 		fprintf(stderr,
@@ -192,6 +193,9 @@
 				__FUNCTION__, strerror(errno));
 		strcpy(server_name, "localhost");
 	}
+#else
+	strcpy(server_name, "localhost");
+#endif
 
 	server->projects = lash_list_append(server->projects, project);
 
