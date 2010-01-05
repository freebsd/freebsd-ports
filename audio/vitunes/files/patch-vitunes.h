--- ./vitunes.h.orig	2010-01-04 03:17:55.000000000 +0100
+++ ./vitunes.h	2010-01-05 18:33:18.000000000 +0100
@@ -1,10 +1,13 @@
 #ifndef VITUNES_H
 #define VITUNES_H
 
+#include <signal.h>
 #include <sys/time.h>
 #include <locale.h>
-#include <util.h>
+//#include <util.h>
 #include <pwd.h>
+#include <unistd.h>
+#include <getopt.h>
 
 #include "input_handlers.h"
 #include "uinterface.h"
