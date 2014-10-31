https://github.com/mono/mono/pull/371

--- eglib/src/gmisc-unix.c~
+++ eglib/src/gmisc-unix.c
@@ -93,24 +93,27 @@ get_pw_data (void)
 		pthread_mutex_unlock (&pw_lock);
 		return;
 	}
+
+	home_dir = g_getenv ("HOME");
+	user_name = g_getenv ("USER");
+
 #ifdef HAVE_GETPWUID_R
-	if (getpwuid_r (getuid (), &pw, buf, 4096, &result) == 0) {
-		home_dir = g_strdup (pw.pw_dir);
-		user_name = g_strdup (pw.pw_name);
+	if (home_dir == NULL || user_name == NULL) {
+		if (getpwuid_r (getuid (), &pw, buf, 4096, &result) == 0) {
+			if (home_dir == NULL)
+				home_dir = g_strdup (pw.pw_dir);
+			if (user_name == NULL)
+				user_name = g_strdup (pw.pw_name);
+		} else {
+			if (user_name == NULL)
+				user_name = "somebody";
+		}
 	}
 #endif
-	if (home_dir == NULL)
-		home_dir = g_getenv ("HOME");
 
-	if (user_name == NULL) {
-		user_name = g_getenv ("USER");
-		if (user_name == NULL)
-			user_name = "somebody";
-	}
 	pthread_mutex_unlock (&pw_lock);
 }
 
-/* Give preference to /etc/passwd than HOME */
 const gchar *
 g_get_home_dir (void)
 {
