--- Kaid.cc	Sun Feb  6 00:18:03 2005
--- Kaid.cc	Wed Mar  2 08:52:16 2005
@@ -8,7 +8,11 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifndef PLATFORM_freebsd
 #include <getopt.h>
+#else
+#include <unistd.h>
+#endif
 
 #include "Kaid.h"
 #include "KaiDaemon.h"
@@ -196,12 +200,8 @@
     openlog("kaid", LOG_PID, LOG_DAEMON);
     try
     {
-        while(1)
+        while((c = getopt (argc, argv, "c:dho:sf:V")) != -1)
         {
-            if (c == -1)
-                break;
-
-            c = getopt (argc, argv, "c:dho:sf:V");
             switch(c)
             {
                 case 'h':
