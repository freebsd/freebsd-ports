--- konversation/src/server.cpp.orig	Tue Jun  7 10:44:34 2005
+++ konversation/src/server.cpp	Tue Jun  7 10:44:58 2005
@@ -212,7 +212,7 @@
             }
 
             channels += (*it).name();
-            keys += ((*it).password().isEmpty() ? "''" : (*it).password());
+            keys += ((*it).password().isEmpty() ? QString("''") : (*it).password());
         }
 
         setAutoJoinChannel(channels);
