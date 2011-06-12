
$FreeBSD$

--- src/Clients/MainApp/FSpot.Loaders/GdkImageLoader.cs.orig
+++ src/Clients/MainApp/FSpot.Loaders/GdkImageLoader.cs
@@ -112,7 +112,7 @@
 		public new bool Close ()
 		{
 			lock (sync_handle) {
-				return base.Close (true);
+				return base.Close ();
 			}
 		}
 #endregion
