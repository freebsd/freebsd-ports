--- rr_lib.rb.orig
+++ rr_lib.rb
@@ -22,6 +22,7 @@
 $rr_version = '0.6.0' #application wide setting
 
 begin
+	require 'rubygems'
 	require 'gettext'
 	include GetText
 	bindtextdomain("rubyripper")
@@ -70,6 +71,7 @@
 	Thread.new do
 	 	if installed('eject') ; `eject #{cdrom}`
 		elsif installed('diskutil'); `diskutil eject #{cdrom}` #Mac users don't got eject, but diskutil
+		elsif installed('cdcontrol'); `cdcontrol -f #{cdrom} eject` #FreeBSD has cdcontrol(1) in the base system
 		else puts _("No eject utility found!")
 		end
 	end
@@ -573,15 +575,15 @@
 			end
 		end
 		
-		unless File.blockdev?(@cdrom) #is it a real device?
+		unless File.chardev?(@cdrom) #is it a real device?
 			@error = _("Cdrom drive %s does not exist on your system!\n"\
 			"Please configure your cdrom drive first.") % [@cdrom]
 			@query = false
 			return false
 		end
 			
-		unless (File.readable?(@cdrom) && File.writable?(@cdrom))
-			@error = _("You don't have read and write permission\n"\
+		unless File.readable?(@cdrom)
+			@error = _("You don't have read permissions\n"\
 			"for device %s on your system! These permissions are\n"\
 			"necessary for cdparanoia to scan your drive.\n\n%s\n"\
 			"You might want to add yourself to the necessary group in /etc/group")\
@@ -605,13 +607,13 @@
 			return true
 		end
 		
-		unless ((File.chardev?(device) || File.blockdev?(device)) && File.readable?(device) && File.writable?(device))
+		unless ((File.chardev?(device) || File.blockdev?(device)) && File.readable?(device))
 			permission = nil
 			if File.chardev?(device) && installed('ls')
 				permission = `ls -l #{device}`
 			end
 			
-			@error = _("You don't have read and write permission\n"\
+			@error = _("You don't have read permissions\n"\
 			"for device %s on your system! These permissions are\n"\
 			"necessary for cdparanoia to scan your drive.\n\n%s\n"\
 			"You might want to add yourself to the necessary group in /etc/group")\
@@ -2524,7 +2526,7 @@
 	# 6) is req_matches_all <= req_matches_errors
 
 	def checkConfig
-		unless File.symlink?(@settings['cdrom']) || File.blockdev?(@settings['cdrom'])
+		unless File.symlink?(@settings['cdrom']) || File.chardev?(@settings['cdrom'])
 			@error = ["error", _("The device %s doesn't exist on your system!") % [@settings['cdrom']]]
 			return false
 		end
