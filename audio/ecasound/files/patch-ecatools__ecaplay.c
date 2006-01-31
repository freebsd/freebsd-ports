--- ecatools/ecaplay.c.orig	Mon Oct  3 06:44:57 2005
+++ ecatools/ecaplay.c	Sun Jan 29 21:54:01 2006
@@ -211,9 +211,10 @@
   else {
     static int once = 1;
     if (once) {
+      char *tmpstr;
       eci_command_r(eci, "ao-iselect 1");
       eci_command_r(eci, "ao-describe");
-      char *tmpstr = (char*)eci_last_string_r(eci);
+      tmpstr = (char*)eci_last_string_r(eci);
       /* skip the "-x:" prefix where x is one of [io] */
       while(*tmpstr && *tmpstr++ != ':') 
 	;
