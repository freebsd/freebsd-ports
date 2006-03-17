--- src/common/config/config.cpp.orig	Wed Mar 15 14:17:53 2006
+++ src/common/config/config.cpp	Wed Mar 15 14:18:30 2006
@@ -106,7 +106,7 @@
 	{TYPE_STRING,		"RemoteBindAddress",		(ConfigValue) 0},
 	{TYPE_STRING,		"ExternalFileAccess",		(ConfigValue) "None"},	// location(s) of external files for tables
 	{TYPE_STRING,		"DatabaseAccess",			(ConfigValue) "Full"},	// location(s) of databases
-	{TYPE_STRING,		"UdfAccess",				(ConfigValue) "Restrict UDF"},	// location(s) of UDFs
+	{TYPE_STRING,		"UdfAccess",				(ConfigValue) "Restrict " FB_LIBEXEC_PREFIX "/udf"},	// location(s) of UDFs
 	{TYPE_STRING,		"TempDirectories",			(ConfigValue) 0},
 	{TYPE_BOOLEAN,		"BugcheckAbort",			(ConfigValue) false},	// whether to abort() engine when internal error is found
 	{TYPE_BOOLEAN,		"OldColumnNaming",			(ConfigValue) false}	// if true use old column naming rules
