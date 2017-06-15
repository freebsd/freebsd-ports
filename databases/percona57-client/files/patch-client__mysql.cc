--- client/mysql.cc.orig	2016-11-27 19:44:54 UTC
+++ client/mysql.cc
@@ -1903,11 +1903,11 @@ static void usage(int version)
 #endif
 
 #ifdef HAVE_READLINE
-  printf("%s  Ver %s Distrib %s, for %s (%s) using %s %s\n",
+  printf("%s  Ver %s Distrib %s Percona, for %s (%s) using %s %s\n",
 	 my_progname, VER, MYSQL_SERVER_VERSION, SYSTEM_TYPE, MACHINE_TYPE,
          readline, rl_library_version);
 #else
-  printf("%s  Ver %s Distrib %s, for %s (%s)\n", my_progname, VER,
+  printf("%s  Ver %s Distrib %s Percona, for %s (%s)\n", my_progname, VER,
 	MYSQL_SERVER_VERSION, SYSTEM_TYPE, MACHINE_TYPE);
 #endif
 
