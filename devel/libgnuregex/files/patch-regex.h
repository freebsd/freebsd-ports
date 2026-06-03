--- regex.h.orig	2026-01-27 18:52:19 UTC
+++ regex.h
@@ -29,7 +29,7 @@ extern "C" {
 
 /* Define __USE_GNU to declare GNU extensions that violate the
    POSIX name space rules.  */
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) || defined(__BSD_VISIBLE)
 # define __USE_GNU 1
 #endif
 
