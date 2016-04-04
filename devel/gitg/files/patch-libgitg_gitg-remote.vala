Upstream fix for building against libgit2 0.24.
Should be removed after updating to gitg 3.20.0

--- libgitg/gitg-remote.vala.orig	2015-12-15 14:12:13 UTC
+++ libgitg/gitg-remote.vala
@@ -247,7 +247,7 @@ public class Remote : Ggit.Remote
 			try
 			{
 				yield Async.thread(() => {
-					base.connect(direction, new Callbacks(this, callbacks, null));
+					base.connect(direction, new Callbacks(this, callbacks, null), null);
 				});
 			}
 			catch (Error e)
