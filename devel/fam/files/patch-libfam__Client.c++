--- ./libfam/Client.c++.orig	2003-04-15 06:21:25.000000000 +0200
+++ ./libfam/Client.c++	2014-01-03 02:35:10.000000000 +0100
@@ -34,7 +34,6 @@
 #include <syslog.h>
 #include <errno.h>
 
-#include <iostream.h>
 
 #include "fam.h"
 #include "Client.h"
@@ -264,7 +263,7 @@
         {
             char msg[100];
             snprintf(msg, sizeof(msg),
-                     "change info too long! (%d max)", sizeof(changeInfo));
+                     "change info too long! (%lu max)", (unsigned long)sizeof(changeInfo));
             croakConnection(msg);
             return -1;
         }
