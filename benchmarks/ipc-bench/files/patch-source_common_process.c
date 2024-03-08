--- source/common/process.c.orig	2022-04-28 15:09:32 UTC
+++ source/common/process.c
@@ -55,7 +55,7 @@ pid_t start_process(char *argv[]) {
 		// second is an array of arguments, where the
 		// command path has to be included as well
 		// (that's why argv[0] first)
-		if (execv(argv[0], argv) == -1) {
+		if (execvp(argv[0], argv) == -1) {
 			throw("Error opening child process");
 		}
 	}
@@ -83,24 +83,18 @@ void start_children(char *prefix, int argc, char *argv
 	char server_name[100];
 	char client_name[100];
 
-	char *build_path = find_build_path();
-
 	// clang-format off
 	sprintf(
 		server_name,
-		"%s/%s/%s-%s",
-		build_path,
+		"%s-%s",
 		prefix,
-		prefix,
 		"server"
 	);
 
 	sprintf(
 		client_name,
-		"%s/%s/%s-%s",
-		build_path,
+		"%s-%s",
 		prefix,
-		prefix,
 		"client"
 	);
 	// clang-format on
@@ -111,5 +105,4 @@ void start_children(char *prefix, int argc, char *argv
 	waitpid(c1_id, NULL, WUNTRACED);
 	waitpid(c2_id, NULL, WUNTRACED);
 
-	free(build_path);
 }
