--- ccstruct/polyblk.cpp.orig	2009-09-11 08:36:32.000000000 -0400
+++ ccstruct/polyblk.cpp	2009-09-11 08:38:14.000000000 -0400
@@ -271,6 +271,7 @@
       }
     }
   }
+  delete lines;
 }
 #endif
 
