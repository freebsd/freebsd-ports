--- tools/fileclient.cpp.orig	2003-02-01 14:29:23 UTC
+++ tools/fileclient.cpp
@@ -20,6 +20,8 @@
 
 #include <poslib/poslib.h>
 
+#include <limits.h>
+
 int main(int argc, char **argv) {
   DnsMessage *q = NULL, *a = NULL;
   char q3[PATH_MAX], *q2 = "", *query = q3, *ptr, *ptr2;
