--- src/ossmidi.cc.orig	2007-12-18 19:48:23.000000000 +0100
+++ src/ossmidi.cc	2007-12-18 19:50:01.000000000 +0100
@@ -32,7 +32,8 @@
 
 #include <assert.h>
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <errno.h>
 
@@ -63,6 +64,8 @@
 
 #ifdef HAVE_LINUX_SOUNDCARD_H
 # include <linux/soundcard.h>
+#else
+# include <sys/soundcard.h>
 #endif
 
 #ifdef HAVE_SYS_IOCTL_H
