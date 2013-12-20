--- tools/fileclient.cpp.orig
+++ tools/fileclient.cpp
@@ -20,6 +20,8 @@
 
 #include <poslib/poslib.h>
 
+#include <limits.h>
+
 int main(int argc, char **argv) {
   DnsMessage *q = NULL, *a = NULL;
   char q3[PATH_MAX], *q2 = "", *query = q3, *ptr, *ptr2;
