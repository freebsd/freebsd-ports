Issutracker : #i40191#
CWS         : cws_srx645_bsd01
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : sys/socket.h is needed for FreeBSD

Index: ucbhelper/source/client/proxydecider.cxx
===================================================================
RCS file: /cvs/ucb/ucbhelper/source/client/proxydecider.cxx,v
retrieving revision 1.3.16.1
diff -u -r1.3.16.1 proxydecider.cxx
--- ucbhelper/source/client/proxydecider.cxx	20 Oct 2004 12:04:36 -0000	1.3.16.1
+++ ucbhelper/source/client/proxydecider.cxx	30 Dec 2004 04:12:01 -0000
@@ -127,6 +127,10 @@
 #include <unistd.h>
 #endif
 
+#if defined (FREEBSD)
+#include <sys/socket.h>
+#endif
+
 #ifdef SOLARIS
 
 extern "C"
