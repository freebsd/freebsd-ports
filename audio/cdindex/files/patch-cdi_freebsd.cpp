$FreeBSD$

--- cdi_freebsd.cpp.orig	Sat Mar 30 16:02:52 2002
+++ cdi_freebsd.cpp	Sat Mar 30 16:03:18 2002
@@ -23,6 +23,7 @@
 //____________________________________________________________________________
 
 
+#include <arpa/inet.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
