--- src/utils.vala.orig	2019-08-10 18:20:51 UTC
+++ src/utils.vala
@@ -94,6 +94,35 @@ namespace BookwormApp.Utils {
 		debug("Completed executing async command["+string.joinv(" ", spawn_args)+"]...");
 		return 0;
 	}
+	
+	public int execute_async_command(string[] args) {
+		MainLoop loop = new MainLoop();
+		
+		try {
+			Pid child;
+			
+			Process.spawn_async(
+				"/",
+				args,
+				null,
+				SpawnFlags.SEARCH_PATH | SpawnFlags.DO_NOT_REAP_CHILD,
+				null,
+				out child
+			);
+			
+			ChildWatch.add(child, (pid, status) => {
+				Process.close_pid(pid);
+				
+				loop.quit();
+			});
+			
+			loop.run();
+		} catch (SpawnError error) {
+			warning("ERROR execute_async_command (" + string.joinv(" ", args) + ")");
+		}
+		
+		return 0;
+	}
 
 	public string execute_sync_command (string cmd){
 		debug("Starting to execute sync command ["+cmd+"]...");
