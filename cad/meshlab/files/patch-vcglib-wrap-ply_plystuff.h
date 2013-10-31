--- ../../vcglib/wrap/ply/plystuff.h.orig	2013-10-31 09:44:03.000000000 +0100
+++ ../../vcglib/wrap/ply/plystuff.h	2013-10-31 09:50:52.000000000 +0100
@@ -75,6 +75,7 @@
 #define pb_close  _close
 #define DIR_SEP "\\"
 #else
+#include <unistd.h>
 #define pb_mkdir(n)  mkdir(n,0755)
 #define pb_access access
 #define pb_stat   stat
