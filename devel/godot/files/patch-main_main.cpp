--- main/main.cpp.orig	2016-08-09 07:52:15 UTC
+++ main/main.cpp
@@ -161,7 +161,7 @@ void Main::print_help(const char* p_bina
 	}
 	OS::get_singleton()->print(")\n");
 	OS::get_singleton()->print("\t-ldpi\t : Force low-dpi mode (OSX Only)");
-
+	OS::get_singleton()->print("\n");
 	OS::get_singleton()->print("\t-ad DRIVER\t : Audio Driver (");
 	for (int i=0;i<OS::get_singleton()->get_audio_driver_count();i++) {
 
