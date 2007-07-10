--- lib/monitor.rb.orig	Tue Feb 13 02:01:19 2007
+++ lib/monitor.rb	Tue May 22 22:35:57 2007
@@ -105,14 +105,17 @@
         return false
       ensure
 	Thread.critical = true
-	if timer && timer.alive?
-	  Thread.kill(timer)
+	begin
+	  if timer && timer.alive?
+	    Thread.kill(timer)
+	  end
+	  if @waiters.include?(Thread.current)  # interrupted?
+	    @waiters.delete(Thread.current)
+	  end
+	  @monitor.instance_eval {mon_enter_for_cond(count)}
+	ensure
+	  Thread.critical = false
 	end
-	if @waiters.include?(Thread.current)  # interrupted?
-	  @waiters.delete(Thread.current)
-	end
-        @monitor.instance_eval {mon_enter_for_cond(count)}
-	Thread.critical = false
       end
     end
     
@@ -210,6 +213,7 @@
     Thread.critical = true
     mon_acquire(@mon_entering_queue)
     @mon_count += 1
+  ensure
     Thread.critical = false
   end
   
@@ -299,8 +303,9 @@
   def mon_exit_for_cond
     count = @mon_count
     @mon_count = 0
-    mon_release
     return count
+  ensure
+    mon_release
   end
 end
 
