--- src/main.c
+++ src/main.c
@@ -544,7 +544,7 @@
 	directory_server_t *ds;
 	int i;
 	avl_traverser trav = {0};
-	static main_shutting_down = 0;
+	static int main_shutting_down = 0;
 	
 	thread_library_lock ();
 		if (!main_shutting_down)
