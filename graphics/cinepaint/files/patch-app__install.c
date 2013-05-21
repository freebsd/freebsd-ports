--- app/install.c.orig
+++ app/install.c
@@ -475,7 +475,7 @@
 
   CP_TEXT_INSERT( font_strong, _("User Installation Log\n\n") );
 
-#if 1
+#if 0
 	{	const char* msg = UserInstall(gimp_directory());
 		if(msg)
 		{
