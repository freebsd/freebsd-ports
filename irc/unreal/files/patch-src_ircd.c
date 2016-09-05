--- src/ircd.c.orig	2016-09-03 19:34:06 UTC
+++ src/ircd.c
@@ -1422,12 +1422,12 @@ int InitwIRCD(int argc, char *argv[])
 	}
 #endif
 #ifndef _WIN32
-	mkdir("tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
+	mkdir("/var/run/ircd/tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
  #if defined(USE_LIBCURL) && defined(REMOTEINC_SPECIALCACHE)
  	mkdir("cache", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the cache dir, if using curl and it doesn't exist */
  #endif
 #else
-	mkdir("tmp");
+	mkdir("/var/run/ircd/tmp");
  #if defined(USE_LIBCURL) && defined(REMOTEINC_SPECIALCACHE)
  	mkdir("cache");
  #endif
