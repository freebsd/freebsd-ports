--- dialogs.rb.orig	Fri Mar  2 18:19:37 2001
+++ dialogs.rb	Fri Mar  2 19:15:11 2001
@@ -73,7 +73,7 @@
 class Dialog
 
 	def perform(cmd)
-	options = "--backtitle '#{@title}'"
+	options = if /^--title / =~ cmd then "" else "--title '#{@title}'" end
 	tf=Tempfile.new("dialog")
 	torun=@DIALOG+' '+options+' '+cmd+" 2> #{tf.path}"
 	system(torun)
