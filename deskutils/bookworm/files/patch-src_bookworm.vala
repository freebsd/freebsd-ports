--- src/bookworm.vala.orig	2019-08-10 18:20:51 UTC
+++ src/bookworm.vala
@@ -481,7 +481,11 @@ public class BookwormApp.Bookworm : Granite.Applicatio
 		//Run dicovery of books as a background task if not already running
 		string checkBackgroundTask = BookwormApp.Utils.execute_sync_command("ps -ef");
 		if(checkBackgroundTask.index_of("bookworm --discover") == -1){
-			BookwormApp.Utils.execute_async_multiarg_command_pipes({"com.github.babluboy.bookworm", "--discover", "&"});
+			BookwormApp.Utils.execute_async_command({
+				"com.github.babluboy.bookworm",
+				"--discover",
+				"&"
+			});
 		}else{
     		debug("Bookworm discover process already running....");
 		}
