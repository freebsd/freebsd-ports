$FreeBSD$

--- src/ircd.c	2011-11-05 02:25:24.000000000 -0700
+++ src/ircd.c	2011-11-28 10:21:38.000000000 -0800
@@ -1407,12 +1407,12 @@
 	}
 #endif
 #ifndef _WIN32
-	mkdir("tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
+	mkdir("%%RUNDIR%%/tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
  #if defined(USE_LIBCURL) && defined(REMOTEINC_SPECIALCACHE)
  	mkdir("cache", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the cache dir, if using curl and it doesn't exist */
  #endif
 #else
-	mkdir("tmp");
+	mkdir("%%RUNDIR%%/tmp");
  #if defined(USE_LIBCURL) && defined(REMOTEINC_SPECIALCACHE)
  	mkdir("cache");
  #endif

