--- src/utilities.cc.orig	2010-06-15 14:28:09.000000000 +0800
+++ src/utilities.cc	2011-04-07 17:00:18.000000000 +0800
@@ -227,8 +227,6 @@
 #ifndef __NR_gettid
 #ifdef OS_MACOSX
 #define __NR_gettid SYS_gettid
-#elif ! defined __i386__
-#error "Must define __NR_gettid for non-x86 platforms"
 #else
 #define __NR_gettid 224
 #endif
