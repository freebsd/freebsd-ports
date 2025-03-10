--- host/lib/usrp_clock/octoclock/octoclock_image_loader.cpp.orig	2024-06-10 22:29:18 UTC
+++ host/lib/usrp_clock/octoclock/octoclock_image_loader.cpp
@@ -95,7 +95,7 @@ static void octoclock_validate_firmware_image(octocloc
                                      % session.image_filepath));
     }
 
-    std::string extension = fs::extension(session.image_filepath);
+    const std::string extension = fs::path(session.image_filepath).extension().string();
     if (extension == ".bin") {
         octoclock_read_bin(session);
     } else if (extension == ".hex") {
