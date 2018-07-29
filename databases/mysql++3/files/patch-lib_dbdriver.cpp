https://tangentsoft.com/mysqlpp/info/4f077284dd2ca1b6
https://tangentsoft.com/mysqlpp/info/e5f2c3d83f

Index: lib/dbdriver.cpp
==================================================================
--- lib/dbdriver.cpp.orig	2015-03-19 00:55:17 UTC
+++ lib/dbdriver.cpp
@@ -257,7 +257,11 @@ DBDriver::set_option(unsigned int o, boo
 	}
 	
 	if ((n == 1) &&
+#ifdef CLIENT_LONG_PASSWORD
 			(o >= CLIENT_LONG_PASSWORD) &&
+#else
+			(o >= CLIENT_MYSQL) &&
+#endif
 #if MYSQL_VERSION_ID > 40000	// highest flag value varies by version
 			(o <= CLIENT_MULTI_RESULTS)
 #else
