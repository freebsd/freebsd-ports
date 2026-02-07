--- src/datetime.cpp.orig	2018-01-26 22:55:42.426793000 +0000
+++ src/datetime.cpp	2018-01-26 22:56:08.411257000 +0000
@@ -272,7 +272,7 @@
 # endif
 #endif
       ,ODBCXX_STRING_CONST("%09d"),nanos_);
-      buf[9] = NULL;// Terminate string
+      buf[9] = '\0';// Terminate string
     ret+=ODBCXX_STRING(buf);
   }
   return ret;
