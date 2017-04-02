--- src/gui/splash.cpp.orig	2017-04-02 22:54:21 UTC
+++ src/gui/splash.cpp
@@ -185,9 +185,9 @@ Splash::Splash():
 	if(ran >0.499999)
 		number = 2;
 	//synfig::info("%s", strprintf("%d",number).c_str());
-	splash_image->set(imagepath+"splash_screen"+strprintf("%d",number)+"."IMAGE_EXT);
+	splash_image->set(imagepath+"splash_screen"+strprintf("%d",number)+"." IMAGE_EXT);
 	*/
-	splash_image->set(imagepath+"splash_screen."IMAGE_EXT);
+	splash_image->set(imagepath+"splash_screen." IMAGE_EXT);
 	splash_image->set_alignment(0.5,0.5);
 	splash_image->set_padding(0,0);
 
@@ -220,7 +220,7 @@ Splash::Splash():
   	frame->add(*fixed);
 
 	// Set up the parameters for this pop-up window
-	set_title("Synfig Studio "VERSION);
+	set_title("Synfig Studio " VERSION);
 	set_modal(false);
 	property_window_position().set_value(Gtk::WIN_POS_CENTER);
 	set_resizable(false);
