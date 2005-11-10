--- src/gui.cs.orig	Mon Feb 28 16:08:34 2005
+++ src/gui.cs	Sun Oct 23 17:31:17 2005
@@ -541,8 +541,8 @@
 		private int update_queue_status(string queue)
 		{
 			G_ListView view;
-			Fax.FaxQueue q;
-			Fax.FaxRecQueue rq;
+			Fax.FaxQueue q = null;
+			Fax.FaxRecQueue rq = null;
 						
 			view = lv;
 				
