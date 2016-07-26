--- par2creatorsourcefile.cpp.orig	2004-04-15 13:45:23 UTC
+++ par2creatorsourcefile.cpp
@@ -224,6 +224,10 @@ bool Par2CreatorSourceFile::Open(Command
           cout << newfraction/10 << '.' << newfraction%10 << "%\r" << flush;
         }
       }
+      else
+      {
+        offset += want;
+      }
     }
 
     // Did we finish the last block
