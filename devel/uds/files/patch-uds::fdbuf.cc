--- uds/fdbuf.cc.orig	Thu Sep  5 10:23:14 2002
+++ uds/fdbuf.cc	Thu Sep  5 10:23:23 2002
@@ -22,6 +22,7 @@
 
 // includes
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <uds/stdexcpt.hh>
 #include <uds/fdbuf.hh>
