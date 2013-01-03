--- src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp.orig	2012-12-19 19:27:17.000000000 +0100
+++ src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp	2012-12-20 14:55:59.492850918 +0100
@@ -44,6 +44,7 @@
 #include <netinet/in.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
 
