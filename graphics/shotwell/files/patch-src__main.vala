--- src/main.vala.orig	2010-09-07 10:48:53.000000000 -0300
+++ src/main.vala	2010-09-07 10:49:28.000000000 -0300
@@ -16,9 +16,11 @@
     Unique.Response response = Unique.Response.OK;
     
     switch (command) {
+#if !NO_CAMERA    
         case ShotwellCommand.MOUNTED_CAMERA:
             LibraryWindow.get_app().mounted_camera_shell_notification(data.get_text(), false);
         break;
+#endif
         
         case Unique.Command.ACTIVATE:
             LibraryWindow.get_app().present_with_time(timestamp);
