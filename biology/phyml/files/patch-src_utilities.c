--- src/utilities.c.orig	2020-07-09 11:49:16 UTC
+++ src/utilities.c
@@ -17,6 +17,9 @@ the GNU public licence. See http://www.opensource.org 
 #include "beagle_utils.h"
 #endif
 
+int CALL;
+int TIME;
+
 //////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////
 
@@ -3066,7 +3069,7 @@ int Assign_State_With_Ambiguity(char *c, int datatype,
       if(Is_Ambigu(c,GENERIC,stepsize)) state[0] = T_MAX_ALPHABET-1;
       else
         {
-          char format[6];
+          char format[20];
           sprintf(format,"%%%dd",stepsize);
           if(!sscanf(c,format,state))
             {
@@ -4891,7 +4894,7 @@ int Are_Compatible(char *statea, char *stateb, int ste
       else
         {
           int a,b;
-          char format[6];
+          char format[20];
           
           sprintf(format,"%%%dd",stepsize);
           
