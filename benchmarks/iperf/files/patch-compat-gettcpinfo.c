--- compat/gettcpinfo.c.orig	2021-12-11 04:24:44 UTC
+++ compat/gettcpinfo.c
@@ -97,6 +97,4 @@ inline void gettcpinfo (SOCKET sock, struct ReportStru
     sample->tcpstats.rtt = 1;
     sample->tcpstats.isValid  = false;
 };
-#else
-inline void gettcpinfo (int sock, struct ReportStruct *sample) {
 #endif
