--- regex.h.orig	2020-12-28 19:24:49 UTC
+++ regex.h
@@ -30,7 +30,7 @@ extern "C" {
 
 /* Define __USE_GNU to declare GNU extensions that violate the
    POSIX name space rules.  */
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) || defined(__BSD_VISIBLE)
 # define __USE_GNU 1
 #endif
 
