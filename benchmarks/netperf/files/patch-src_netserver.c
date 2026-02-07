--- src/netserver.c.orig	2021-01-21 16:02:24 UTC
+++ src/netserver.c
@@ -260,8 +260,6 @@ open_debug_file()
 
 #if !defined(WIN32)
 
-  chmod(FileName,0644);
-
   /* redirect stdin to "/dev/null" */
   rd_null_fp = fopen(NETPERF_NULL,"r");
   if (NULL == rd_null_fp) {
