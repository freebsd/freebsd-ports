--- actiondb.cc.orig	2016-07-05 18:32:44 UTC
+++ actiondb.cc
@@ -119,14 +119,9 @@ void Command::run() {
 using namespace std;
 
 void Command::run() {
-	pid_t pid = fork();
-	switch (pid) {
-		case 0:
-			execlp("/bin/sh", "sh", "-c", cmd.c_str(), nullptr);
-			exit(1);
-		case -1:
-			printf(_("Error: can't execute command \"%s\": fork() failed\n"), cmd.c_str());
-	}
+	gchar* argv[] = {(gchar*) "/bin/sh", (gchar*) "-c", NULL, NULL};
+	argv[2] = (gchar *) cmd.c_str();
+	g_spawn_async(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);
 }
 
 ButtonInfo Button::get_button_info() const {
