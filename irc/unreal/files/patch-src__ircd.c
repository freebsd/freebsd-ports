--- ./src/ircd.c.orig	2013-11-24 20:24:26.000000000 +0100
+++ ./src/ircd.c	2014-05-23 00:34:32.000000000 +0200
@@ -1410,12 +1410,12 @@
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
