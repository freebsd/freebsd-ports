#iz XXXXX
sys/socket.h is needed, there should be
appropreate place to give this definition, though.

Index: ucbhelper/source/client/proxydecider.cxx
===================================================================
RCS file: /cvs/ucb/ucbhelper/source/client/proxydecider.cxx,v
retrieving revision 1.3.16.1
diff -u -r1.3.16.1 proxydecider.cxx
--- ucbhelper/source/client/proxydecider.cxx	20 Oct 2004 12:04:36 -0000	1.3.16.1
+++ ucbhelper/source/client/proxydecider.cxx	30 Oct 2004 23:08:26 -0000
@@ -107,6 +107,10 @@
 using namespace com::sun::star;
 using namespace ucbhelper;
 
+#if defined (FREEBSD)
+#include <sys/socket.h>
+#endif
+
 #define CONFIG_ROOT_KEY     "org.openoffice.Inet/Settings"
 #define PROXY_TYPE_KEY      "ooInetProxyType"
 #define NO_PROXY_LIST_KEY   "ooInetNoProxy"
