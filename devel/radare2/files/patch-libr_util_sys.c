--- libr/util/sys.c.orig	2026-06-27 13:05:18 UTC
+++ libr/util/sys.c
@@ -88,9 +88,6 @@ int proc_pidpath(int pid, void * buffer, ut32 buffersi
 # include <sys/wait.h>
 #endif
 # include <signal.h>
-#ifndef __APPLE__
-extern char **environ;
-#endif
 
 #ifdef __HAIKU__
 # define Sleep sleep
@@ -448,12 +445,16 @@ R_API bool r_sys_clearenv(void) {
 		}
 	}
 #else
-	if (!environ) {
-		return false;
-	}
-	while (*environ) {
-		*environ++ = NULL;
-	}
+    if (!Genv) {
+	r_sys_env_init ();
+    }
+    char **e = Genv;
+    if (!e) {
+	return false;
+    }
+    while (*e) {
+	*e++ = NULL;
+    }
 #endif
 	return true;
 #else
@@ -1414,8 +1415,6 @@ R_API char **r_sys_get_environ(void) {
 	}
 #if __APPLE__ && !HAVE_ENVIRON
 	Genv = *_NSGetEnviron();
-#else
-	Genv = environ;
 #endif
 	// return environ if available??
 	if (!Genv) {
