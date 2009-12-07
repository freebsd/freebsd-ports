Index: lib/imlib/imfuncs.h
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/imlib/imfuncs.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- lib/imlib/imfuncs.h	7 Dec 2009 06:36:04 -0000	1.1.1.1
+++ lib/imlib/imfuncs.h	7 Dec 2009 06:44:58 -0000	1.2
@@ -60,7 +60,7 @@ extern void IMSendBadLength _Pt_((IMConn
 /*
  * Transport layer functions (defined in imxport.c)
  */
-extern int IMCreateTCPService _Pt_((int *portp));
+extern int IMCreateTCPService _Pt_((int *portp, char *listenaddr));
 extern IMConnection *IMTCPConnection _Pt_((Widget protocol, int socket));
 extern int IMCreateUnixService _Pt_((char *path));
 extern IMConnection *IMUnixConnection _Pt_((Widget protocol, int socket));
