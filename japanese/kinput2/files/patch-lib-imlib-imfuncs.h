--- lib/imlib/imfuncs.h.orig	2002-10-03 18:35:30.000000000 +0900
+++ lib/imlib/imfuncs.h	2008-11-02 01:08:11.000000000 +0900
@@ -60,7 +60,7 @@
 /*
  * Transport layer functions (defined in imxport.c)
  */
-extern int IMCreateTCPService _Pt_((int *portp));
+extern int IMCreateTCPService _Pt_((int *portp, char *listenaddr));
 extern IMConnection *IMTCPConnection _Pt_((Widget protocol, int socket));
 extern int IMCreateUnixService _Pt_((char *path));
 extern IMConnection *IMUnixConnection _Pt_((Widget protocol, int socket));
