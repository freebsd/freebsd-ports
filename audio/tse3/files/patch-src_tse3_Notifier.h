--- src/tse3/Notifier.h	2004-07-13 13:42:54.171911848 -0400
+++ src/tse3/Notifier.h	2004-07-13 13:46:50.128041064 -0400
@@ -290,7 +290,7 @@
                 const p4_type       &p4;                                 // (*)
         };
 
-    };
+    }
 
     /**************************************************************************
      * Public Notifier framework API
@@ -367,7 +367,7 @@
              */
             typedef Listener<interface_type> listener_type;
 
-            friend class listener_type;
+            friend class Listener<interface_type>;
 
         protected:
 
@@ -602,7 +602,7 @@
                 if (notifiers.erase(notifier)) notifier->detach(this);
             }
 
-            friend class notifier_type;
+            friend class Notifier<interface_type>;
 
         protected:
  API