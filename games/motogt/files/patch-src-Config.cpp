--- src/Config.cpp.orig	2011-01-18 06:52:35.000000000 +0300
+++ src/Config.cpp	2014-02-02 21:13:04.124154052 +0400
@@ -139,6 +139,9 @@
 }
 
 void Config::ChangeResolution(bool up) {
+	if (num_modes == 0)
+		return;
+
 	if (cur_mode!=num_modes) cur_mode+=up?1:num_modes-1;
 	cur_mode=cur_mode%num_modes;
 	real_w=modes_w[cur_mode];
@@ -226,7 +229,8 @@
 		old_fullscreen=fullscreen;
 		changed=false;
 		ofstream fil((home_dir+"settings.lst").c_str(),ios::trunc);
-		fil<<"version="<<(config->version=VERSION)<<endl;
+		fil<<"version="<<VERSION<<endl;
+		if (config) config->version = VERSION;
 		fil<<"fullscreen="<<(fullscreen?1:0)<<endl;
 		fil<<"low_textures="<<(low_textures?1:0)<<endl;
 		fil<<"sound="<<(sound_on?1:0)<<endl;
