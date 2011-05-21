--- OCFPCSC1.cpp.orig	2011-05-12 01:27:28.000000000 +0200
+++ OCFPCSC1.cpp	2011-05-12 01:31:53.000000000 +0200
@@ -140,7 +140,7 @@
   CONTEXT_INFO cInfo;
 
   /* check if context exists */
-  if (cPos = isContextAvailable((long)context) < 0) {
+  if ((cPos = isContextAvailable((long)context)) < 0) {
     throwPcscException(env, obj, "SCardConnect", "PC/SC Wrapper Error: context not in table", 0);
     return 0;
   }
