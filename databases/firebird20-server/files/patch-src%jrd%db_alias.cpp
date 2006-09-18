--- src/jrd/db_alias.cpp.orig	Tue Aug 15 23:07:31 2006
+++ src/jrd/db_alias.cpp	Tue Aug 15 23:10:08 2006
@@ -33,8 +33,8 @@
 
 bool ResolveDatabaseAlias(const string& alias, string& database)
 {
-	string alias_filename;
-	Firebird::Prefix(alias_filename, ALIAS_FILE);
+	string alias_filename = string(FB_CONF_PREFIX)
+		+ PathUtils::dir_sep + ALIAS_FILE;
 	ConfigFile aliasConfig(false);
 	aliasConfig.setConfigFilePath(alias_filename);
 
