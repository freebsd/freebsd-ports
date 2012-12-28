--- client/mysql.cc.orig	2012-02-27 19:15:22.271243107 +0000
+++ client/mysql.cc	2012-02-27 19:16:16.645241508 +0000
@@ -1601,11 +1601,11 @@
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
 
