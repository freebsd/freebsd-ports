Index: ucbhelper/source/client/proxydecider.cxx
===================================================================
RCS file: /cvs/ucb/ucbhelper/source/client/proxydecider.cxx,v
retrieving revision 1.4
diff -u -r1.4 proxydecider.cxx
--- ucbhelper/source/client/proxydecider.cxx	3 Nov 2004 08:03:28 -0000	1.4
+++ ucbhelper/source/client/proxydecider.cxx	21 Nov 2004 00:08:25 -0000
@@ -128,6 +128,9 @@
 #include <unistd.h>
 #endif
 
+#ifdef FREEBSD
+#include <sys/socket.h>
+#endif
 namespace
 {
 
