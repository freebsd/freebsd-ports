--- lashd/client_event.c.orig	2007-01-13 22:05:54 UTC
+++ lashd/client_event.c
@@ -185,6 +185,7 @@ server_lash_event_project_add(server_t *
 		project_set_name(project, name);
 	}
 
+#if 0
 	err = gethostname(server_name, MAXHOSTNAMELEN);
 	if (err == -1) {
 		fprintf(stderr,
@@ -192,6 +193,9 @@ server_lash_event_project_add(server_t *
 				__FUNCTION__, strerror(errno));
 		strcpy(server_name, "localhost");
 	}
+#else
+	strcpy(server_name, "localhost");
+#endif
 
 	server->projects = lash_list_append(server->projects, project);
 
