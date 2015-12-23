--- arg.c.orig	2013-01-23 02:14:58 UTC
+++ arg.c
@@ -40,7 +40,7 @@ process_arg(ArgumentState *arg_state, in
           *(double *)desc[i].location = atof(arg);
           break;
         case 'L':
-          *(int64 *)desc[i].location = atoll(arg);
+          *(int64 *)desc[i].location = strtoll(arg,NULL,10);
           break;
         case 'S': strncpy((char *)desc[i].location,arg, atoi(desc[i].type+1));
           break;
