--- par2creatorsourcefile.cpp.orig	2009-03-10 07:10:35.860499029 +0000
+++ par2creatorsourcefile.cpp	2009-03-10 07:12:53.111712521 +0000
@@ -224,6 +224,10 @@
           cout << newfraction/10 << '.' << newfraction%10 << "%\r" << flush;
         }
       }
+      else
+      {
+        offset += want;
+      }
     }
 
     // Did we finish the last block
