--- sql/mysqld.cc.orig	Tue Dec 14 13:40:36 2004
+++ sql/mysqld.cc	Mon Jan 10 00:28:52 2005
@@ -128,7 +128,7 @@
 #endif /* __WIN__ */
 
 #ifdef HAVE_LIBWRAP
-#include <tcpd.h>
+#include "mytcpd.h"
 #include <syslog.h>
 #ifdef NEED_SYS_SYSLOG_H
 #include <sys/syslog.h>
--- sql/mysqld.cc	2007-11-29 10:52:36 +0000
+++ sql/mysqld.cc	2008-02-29 09:55:00 +0000
@@ -390,6 +390,7 @@
 char compiled_default_collation_name[]= MYSQL_DEFAULT_COLLATION_NAME;
 char *language_ptr, *default_collation_name, *default_character_set_name;
 char mysql_data_home_buff[2], *mysql_data_home=mysql_real_data_home;
+char mysql_unpacked_real_data_home[FN_REFLEN];
 struct passwd *user_info;
 char server_version[SERVER_VERSION_LENGTH];
 char *mysqld_unix_port, *opt_mysql_tmpdir;
@@ -6896,6 +6897,9 @@
     pos[1]= 0;
   }
   convert_dirname(mysql_real_data_home,mysql_real_data_home,NullS);
+  (void) fn_format(buff, mysql_real_data_home, "", "",
+                   (MY_RETURN_REAL_PATH|MY_RESOLVE_SYMLINKS));
+  (void) unpack_dirname(mysql_unpacked_real_data_home, buff);
   convert_dirname(language,language,NullS);
   (void) my_load_path(mysql_home,mysql_home,""); // Resolve current dir
   (void) my_load_path(mysql_real_data_home,mysql_real_data_home,mysql_home);

