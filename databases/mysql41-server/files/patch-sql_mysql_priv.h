--- sql/mysql_priv.h	2007-11-09 12:05:01 +0000
+++ sql/mysql_priv.h	2008-02-29 09:55:00 +0000
@@ -890,6 +890,7 @@
 extern time_t start_time;
 extern char *mysql_data_home,server_version[SERVER_VERSION_LENGTH],
 	    mysql_real_data_home[], *opt_mysql_tmpdir, mysql_charsets_dir[],
+	    mysql_unpacked_real_data_home[],
             def_ft_boolean_syntax[sizeof(ft_boolean_syntax)];
 #define mysql_tmpdir (my_tmpdir(&mysql_tmpdir_list))
 extern MY_TMPDIR mysql_tmpdir_list;

