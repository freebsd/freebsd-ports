Index: lib/imlib/imfuncs.h
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/imlib/imfuncs.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
--- lib/imlib/imfuncs.h.orig	2002-10-03 09:35:30 UTC
+++ lib/imlib/imfuncs.h
@@ -60,7 +60,7 @@ extern void IMSendBadLength _Pt_((IMConn
 /*
  * Transport layer functions (defined in imxport.c)
  */
-extern int IMCreateTCPService _Pt_((int *portp));
+extern int IMCreateTCPService _Pt_((int *portp, char *listenaddr));
 extern IMConnection *IMTCPConnection _Pt_((Widget protocol, int socket));
 extern int IMCreateUnixService _Pt_((char *path));
 extern IMConnection *IMUnixConnection _Pt_((Widget protocol, int socket));
