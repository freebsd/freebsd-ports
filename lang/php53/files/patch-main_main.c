--- main/main.c.orig	Sat Dec 10 09:36:39 2005
+++ main/main.c	Sat Dec 10 09:37:37 2005
@@ -311,7 +311,7 @@
 	PHP_INI_ENTRY("smtp_port",					"25",		PHP_INI_ALL,		NULL)
 	PHP_INI_ENTRY("browscap",					NULL,		PHP_INI_SYSTEM,		NULL)
 #if MEMORY_LIMIT
-	PHP_INI_ENTRY("memory_limit",				"8M",		PHP_INI_ALL,		OnChangeMemoryLimit)
+	PHP_INI_ENTRY("memory_limit",				"12M",		PHP_INI_ALL,		OnChangeMemoryLimit)
 #endif
 	PHP_INI_ENTRY("precision",					"14",		PHP_INI_ALL,		OnSetPrecision)
 	PHP_INI_ENTRY("sendmail_from",				NULL,		PHP_INI_ALL,		NULL)
