--- src/main.c.orig	2023-02-20 11:38:18 UTC
+++ src/main.c
@@ -41,6 +41,7 @@
 #include <arpa/inet.h>
 #include <syslog.h>
 #include <sys/time.h>
+#include <limits.h>
 
 #include "ftp.h"
 #include "ip-lib.h"
@@ -55,8 +56,11 @@
 
 
 char	*program =		"";
-char	progname[80] =		"";
+char	progname[PATH_MAX] =	"";
 
+char pidfile[PATH_MAX];
+struct pidfh *pfh;
+
 int	debug =			0;
 int	extralog =		0;
 
@@ -88,6 +92,8 @@ int main(int argc, char *argv[], char *envp[])
 		program = progname;
 		}
 
+	copy_string(pidfile, PIDFILE_DEFAULT, sizeof(pidfile));
+
 	config = allocate(sizeof(config_t));
 	config->timeout = 15 * 60;
         config->allow_passwdblanks = 0;
@@ -146,6 +152,12 @@ int main(int argc, char *argv[], char *envp[])
 				config->dataport = strtoul(argv[k++], NULL, 10);
 				if (config->dataport == 0)
 					config->dataport = 20;
+				}
+			else if (c == 'P') {
+				if (k >= argc)
+					missing_arg(c, "pid file name");
+
+				copy_string(pidfile, argv[k++], sizeof(pidfile));
 				}
 			else if (c == 'q') {
 
