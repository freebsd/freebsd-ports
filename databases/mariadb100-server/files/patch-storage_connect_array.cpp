--- storage/connect/array.cpp.orig	2014-09-25 00:29:47.000000000 +0200
+++ storage/connect/array.cpp	2014-09-27 12:00:33.000000000 +0200
@@ -129,7 +129,7 @@
         break;
       case TYPE_VOID:
         // Integer stored inside pp->Value
-        par->AddValue(g, (int)parmp->Value);
+        par->AddValue(g, *(int*)parmp->Value);
         break;
       } // endswitch valtyp
 
