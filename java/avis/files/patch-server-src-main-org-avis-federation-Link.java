--- server/src/main/org/avis/federation/Link.java-orig	2008-01-21 18:05:26.000000000 +1030
+++ server/src/main/org/avis/federation/Link.java	2008-01-29 17:16:37.334636622 +1030
@@ -302,7 +285,7 @@
 
   private void handleAck (Ack ack)
   {
-    if (ack.request instanceof FedSubReplace)
+    if (ack.request.getClass () == FedSubReplace.class)
       subscribed = true;
   }
 
@@ -409,3 +392,5 @@
     return newRouting;
   }
 }
+
+
