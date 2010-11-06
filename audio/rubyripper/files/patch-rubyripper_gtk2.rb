--- rubyripper_gtk2.rb.orig
+++ rubyripper_gtk2.rb
@@ -248,13 +248,13 @@
 	def handle_tray
 		@buttons.each{|button| button.sensitive = false}
 		Thread.new do
-			if installed('eject')
+			if installed('cdcontrol')
 				if @buttontext[2].text == _("Open tray")
 					@instances['GtkMetadata'] = false
 					@instances['ShortMessage'].open_tray(@settings['cdrom'])
 					change_display(@instances['ShortMessage'])
 					cancelTocScan()
-					`eject #{@settings['cdrom']}` # spit the cd out
+					`cdcontrol -f #{@settings['cdrom']} eject` # spit the cd out
 					@buttontext[2].set_text('_'+_("Close tray"),true)
 					@buttonicons[2].stock = Gtk::Stock::GOTO_TOP
 					@instances['ShortMessage'].ask_for_disc
@@ -262,7 +262,7 @@
 				else
 					@instances['ShortMessage'].close_tray(@settings['cdrom'])
 					change_display(@instances['ShortMessage'])
-					`eject --trayclose #{@settings['cdrom']}` # close the tray
+					`cdcontrol -f #{@settings['cdrom']} close` # close the tray
 					@buttontext[2].set_text('_'+_("Open tray"),true)
 					@buttonicons[2].stock = Gtk::Stock::GOTO_BOTTOM
 					scan_drive()
