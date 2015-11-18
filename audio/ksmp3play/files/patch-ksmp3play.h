--- ksmp3play.h.orig	2008-04-14 00:22:27 UTC
+++ ksmp3play.h
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
@@ -43,6 +44,7 @@ struct option
 # define required_argument 1
 # define optional_argument 2
 #endif
+*/
 #define BUFLEN 200
 #ifdef HAVE_CONFIG_H
 #include <config.h>
