--- gsmlib/gsm_unix_serial.cc.orig	Thu Jul 17 20:44:42 2003
+++ gsmlib/gsm_unix_serial.cc	Thu Jul 17 20:44:54 2003
@@ -16,6 +16,7 @@
 #include <gsmlib/gsm_nls.h>
 #include <gsmlib/gsm_unix_serial.h>
 #include <gsmlib/gsm_util.h>
+#include <assert.h>
 #include <termios.h>
 #include <fcntl.h>
 #include <iostream>
