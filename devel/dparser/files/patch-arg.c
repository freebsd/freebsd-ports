--- arg.c.orig	Fri Nov  7 03:03:52 2003
+++ arg.c	Mon Feb  2 18:35:43 2004
@@ -40,7 +40,7 @@
           *(double *)desc[i].location = atof(arg);
           break;
         case 'L':
-          *(int64 *)desc[i].location = atoll(arg);
+          *(int64 *)desc[i].location = strtoll(arg,NULL,10);
           break;
         case 'S': strncpy((char *)desc[i].location,arg, atoi(desc[i].type+1));
           break;
