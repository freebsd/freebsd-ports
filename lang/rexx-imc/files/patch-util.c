--- util.c.orig	2002-02-26 12:29:20 UTC
+++ util.c
@@ -1404,7 +1404,7 @@ int line1;           /* if nonzero, the 
             else token=0;
          }
          else if(token>=Command&&start){ /* at the start must be a "command" */
-            if(token==THEN);             /* except THEN, PULL and ARG */
+            if(token==THEN||token==UPPER); /* except THEN, UPPER, PULL and ARG */
             else if(token==ARG||token==PULL)
                prgptr++[0]=PARSE,
                prgptr++[0]=UPPER,
@@ -1415,7 +1415,7 @@ int line1;           /* if nonzero, the 
          if(!token); /* no need to check if there is no token */
          else if(token==VALUE)if(last==ADDRESS||last==FORM||last==TRACE
                                ||last==PARSE||last==SIGNAL);else token=0;
-         else if(token==UPPER)if(last==PARSE);else token=0;
+         else if(token==UPPER)if(start||last==PARSE);else token=0;
          else if(token>=PULL&&token<=LINEIN)if(last==PARSE);else token=0;
          else if(token==WITH)if(first==VALUE);else token=0;
          else if(token==ON||token==OFF)if(last==SIGNAL||last==CALL)
