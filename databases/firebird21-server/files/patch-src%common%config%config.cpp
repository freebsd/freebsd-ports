--- src/common/config/config.cpp.orig	Tue Aug 15 22:53:43 2006
+++ src/common/config/config.cpp	Tue Aug 15 22:54:38 2006
@@ -111,7 +111,7 @@
 	{TYPE_STRING,		"RemoteBindAddress",		(ConfigValue) 0},
 	{TYPE_STRING,		"ExternalFileAccess",		(ConfigValue) "None"},	// location(s) of external files for tables
 	{TYPE_STRING,		"DatabaseAccess",			(ConfigValue) "Full"},	// location(s) of databases
-	{TYPE_STRING,		"UdfAccess",				(ConfigValue) "Restrict UDF"},	// location(s) of UDFs
+	{TYPE_STRING,		"UdfAccess",				(ConfigValue) "Restrict " FB_LIBEXEC_PREFIX "/UDF"},	// location(s) of UDFs
 	{TYPE_STRING,		"TempDirectories",			(ConfigValue) 0},
 #ifdef DEV_BUILD
  	{TYPE_BOOLEAN,		"BugcheckAbort",			(ConfigValue) true},	// whether to abort() engine when internal error is found
