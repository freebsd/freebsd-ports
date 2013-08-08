--- src/oxyd.cc.orig	2007-09-08 16:20:02.000000000 +0400
+++ src/oxyd.cc	2013-08-07 20:36:58.150878990 +0400
@@ -130,7 +130,7 @@
         }
     }
 
-    GridLoc to_gridloc (const SignalLocation &a)
+    GridLoc signal_to_gridloc (const SignalLocation &a)
     {
         assert (a.getGridType() >= GridType_First &&
                 a.getGridType() <= GridType_Last);
@@ -644,8 +644,8 @@
         int nrec = level.getNumRecipients(sender);
         for (int irec=0; irec<nrec; ++irec) {
             SignalLocation recipient = level.getRecipient(sender, irec);
-            GridLoc src = to_gridloc(sender);
-            GridLoc dst = to_gridloc(recipient);
+            GridLoc src = signal_to_gridloc(sender);
+            GridLoc dst = signal_to_gridloc(recipient);
             world::AddSignal (src, dst, "signal");
         }
     }
