--- php_mssql.c	2005/12/06 18:47:14	1.152.2.10
+++ php_mssql.c	2005/12/21 22:43:06	1.152.2.11
@@ -141,6 +141,9 @@
 	STD_PHP_INI_BOOLEAN("mssql.datetimeconvert",  		"1",	PHP_INI_ALL,	OnUpdateBool,	datetimeconvert,			zend_mssql_globals,		mssql_globals)
 	STD_PHP_INI_BOOLEAN("mssql.secure_connection",		"0",	PHP_INI_SYSTEM, OnUpdateBool,	secure_connection,			zend_mssql_globals,		mssql_globals)
 	STD_PHP_INI_ENTRY_EX("mssql.max_procs",				"-1",	PHP_INI_ALL,	OnUpdateLong,	max_procs,					zend_mssql_globals,		mssql_globals,	display_link_numbers)
+#ifdef HAVE_FREETDS
+	STD_PHP_INI_ENTRY("mssql.charset",					"",		PHP_INI_ALL,	OnUpdateString,	charset,					zend_mssql_globals,		mssql_globals)
+#endif
 PHP_INI_END()
 
 /* error handler */
@@ -495,7 +498,9 @@
 #endif
 
 #ifdef HAVE_FREETDS
-		DBSETLCHARSET(mssql.login, "ISO-8859-1");
+		if (MS_SQL_G(charset) && strlen(MS_SQL_G(charset))) {
+			DBSETLCHARSET(mssql.login, MS_SQL_G(charset));
+		}
 #endif
 
 	DBSETLAPP(mssql.login,MS_SQL_G(appname));
