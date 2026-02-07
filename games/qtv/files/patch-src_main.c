--- src/main.c.orig	2025-02-16 14:10:58 UTC
+++ src/main.c
@@ -274,6 +274,12 @@ int main(int argc, char **argv)
 	}
 	#endif // _WIN32
 
+	// Disable buffering for stdout and stderr to avoid issues when output
+	// is redirected to a file or pipe instead of being displayed in a
+	// terminal.
+	setbuf(stdout, NULL);
+	setbuf(stderr, NULL);
+
 	memset(&g_cluster, 0, sizeof(g_cluster));
 
 	g_cluster.tcpsocket   = INVALID_SOCKET;
