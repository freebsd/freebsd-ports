--- ksmp3play.h.orig	Sun Nov  4 20:25:57 2001
+++ ksmp3play.h	Sun Nov  4 20:26:42 2001
@@ -29,8 +29,9 @@
 #include <errno.h>
 #include <time.h>
 #include <smpeg/smpeg.h>
-#ifdef __linux__
+/* #ifdef __linux__ */
 #include <getopt.h>
+/*
 #else
 struct option
 {
@@ -43,6 +44,7 @@
 # define required_argument 1
 # define optional_argument 2
 #endif
+*/
 #define BUFLEN 200
 #ifdef HAVE_CONFIG_H
 #include <config.h>
