--- arg.c.orig	2019-01-10 00:20:05 UTC
+++ arg.c
@@ -31,7 +31,7 @@ void process_arg(ArgumentState *arg_state, int i, char
           *(double *)desc[i].location = atof(arg);
           break;
         case 'L':
-          *(int64 *)desc[i].location = atoll(arg);
+          *(int64 *)desc[i].location = strtoll(arg,NULL,10);
           break;
         case 'S':
           strncpy((char *)desc[i].location, arg, atoi(desc[i].type + 1));
@@ -143,7 +143,7 @@ void usage(ArgumentState *arg_state, char *arg_unused)
 #if defined(__alpha)
                 " %-9ld",
 #else
-#if defined(FreeBSD)
+#if defined(__FreeBSD__)
                 " %-9qd",
 #else
                 " %-9" PRId64,
