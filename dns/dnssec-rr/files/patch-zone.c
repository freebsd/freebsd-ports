--- zone.c.orig	2025-06-21 08:09:31 UTC
+++ zone.c
@@ -4,6 +4,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #include "dnssec.h"
 
 struct input {
