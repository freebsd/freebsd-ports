--- src/jrd/db_alias.cpp.orig	Mon Aug 18 01:16:41 2003
+++ src/jrd/db_alias.cpp	Mon Jul 25 15:07:45 2005
@@ -37,8 +37,8 @@
 
 bool ResolveDatabaseAlias(const char* alias, char* database)
 {
-	TEXT alias_filename[MAXPATHLEN];
-	gds__prefix(alias_filename, const_cast<char*>(ALIAS_FILE));
+	TEXT alias_filename[MAXPATHLEN] = FB_CONF_PREFIX "/";
+	strlcat(alias_filename, ALIAS_FILE, MAXPATHLEN);
 	ConfigFile aliasConfig(false);
 	aliasConfig.setConfigFile(alias_filename);
 
