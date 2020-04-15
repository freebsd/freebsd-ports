--- actiondb.cc.orig	2013-03-27 15:52:38 UTC
+++ actiondb.cc
@@ -118,14 +118,9 @@ template<class Archive> void StrokeInfo::serialize(Arc
 using namespace std;
 
 void Command::run() {
-	pid_t pid = fork();
-	switch (pid) {
-		case 0:
-			execlp("/bin/sh", "sh", "-c", cmd.c_str(), NULL);
-			exit(1);
-		case -1:
-			printf(_("Error: can't execute command \"%s\": fork() failed\n"), cmd.c_str());
-	}
+	gchar* argv[] = {(gchar*) "/bin/sh", (gchar*) "-c", NULL, NULL};
+	argv[2] = (gchar *) cmd.c_str();
+	g_spawn_async(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);
 }
 
 ButtonInfo Button::get_button_info() const {
