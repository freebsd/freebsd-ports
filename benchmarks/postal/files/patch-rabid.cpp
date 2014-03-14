--- rabid.cpp.orig
+++ rabid.cpp
@@ -7,15 +7,14 @@
 #include <cstdlib>
 #include <unistd.h>
 #include <sys/wait.h>
-#include <signal.h>
-#include <stdio.h>
-#include <strings.h>
+#include <csignal>
+#include <cstdio>
+#include <cstring>
+#include <strings.h>
 #include "postal.h"
 #include "logit.h"
 #ifdef USE_GNUTLS
-#include <errno.h>
-#include <gcrypt.h>
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
+#include <cerrno>
 #endif
 
 void usage()
