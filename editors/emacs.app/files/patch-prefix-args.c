--- src/prefix-args.c.orig	2006-03-11 05:06:05.000000000 +0100
+++ src/prefix-args.c	2008-03-23 18:34:13.000000000 +0100
@@ -45,6 +45,8 @@
    I'm quitting and taking up gardening.  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include "GNUstepBase/GSConfig.h"
 
 int
 main (argc, argv)
