--- config/auto-aux/async_io.c	2012-11-01 17:36:02.000000000 +0100
+++ config/auto-aux/async_io.c.orig	2012-11-01 17:35:46.000000000 +0100
@@ -13,7 +13,8 @@
 
 /* $Id: async_io.c 11156 2011-07-27 14:17:02Z doligez $ */
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <signal.h>
