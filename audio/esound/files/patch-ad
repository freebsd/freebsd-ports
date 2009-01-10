--- esdlib.c.orig	2008-11-18 15:35:19.000000000 -0500
+++ esdlib.c	2008-11-20 14:32:59.000000000 -0500
@@ -21,6 +21,8 @@
 #include <errno.h>
 #include <sys/wait.h>
 #include <poll.h>
+#include <pwd.h>
+#include <limits.h>
 
 #include <sys/un.h>
 
@@ -928,7 +930,7 @@ int esd_open_sound( const char *rhost )
 		    putenv(preload2);
 		}
 	    cmd = malloc(strlen(SERVERDIR"/esd  -spawnfd 9999999999") + strlen(esd_spawn_options));
-	    sprintf(cmd, "%s/esd %s -spawnfd %d", SERVERDIR, esd_spawn_options, esd_pipe[1]);
+	    sprintf(cmd, "exec esd %s -spawnfd %d", esd_spawn_options?esd_spawn_options:"", esd_pipe[1]);
 
 	    if(!fork()) {
 		/* child of child process.  Minimal so startup overhead is
@@ -1747,3 +1749,34 @@ int esd_close( int esd )
     return close( esd );
 }
 
+char *
+esd_unix_socket_dir(void) {
+       static char *sockdir = NULL, sockdirbuf[PATH_MAX];
+       struct passwd *pw;
+
+       if (sockdir != NULL)
+               return (sockdir);
+       pw = getpwuid(getuid());
+       if (pw == NULL || pw->pw_dir == NULL) {
+               fprintf(stderr, "esd: could not find home directory\n");
+               exit(1);
+       }
+       snprintf(sockdirbuf, sizeof(sockdirbuf), "%s/.esd", pw->pw_dir);
+       endpwent();
+       sockdir = sockdirbuf;
+       return (sockdir);
+}
+
+char *
+esd_unix_socket_name(void) {
+       static char *sockname = NULL, socknamebuf[PATH_MAX];
+
+       if (sockname != NULL)
+               return (sockname);
+       snprintf(socknamebuf, sizeof(socknamebuf), "%s/socket",
+           esd_unix_socket_dir());
+       sockname = socknamebuf;
+       return (sockname);
+ }
+
+
