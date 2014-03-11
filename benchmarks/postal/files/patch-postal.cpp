--- postal.cpp.orig
+++ postal.cpp
@@ -6,15 +6,11 @@
 #include "smtp.h"
 #include <unistd.h>
 #include <sys/wait.h>
-#include <signal.h>
-#include <stdio.h>
+#include <csignal>
+#include <cstdio>
+#include <cstdlib>
 #include "postal.h"
 #include "logit.h"
-#ifdef USE_GNUTLS
-#include <errno.h>
-#include <gcrypt.h>
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
-#endif
 
 void usage()
 {
