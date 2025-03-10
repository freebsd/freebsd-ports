--- host/lib/usrp/x300/x300_image_loader.cpp.orig	2024-06-10 22:29:18 UTC
+++ host/lib/usrp/x300/x300_image_loader.cpp
@@ -138,8 +138,8 @@ static void x300_validate_image(x300_session_t& sessio
             boost::format("Could not find image at path \"%s\".") % session.filepath));
     }
 
-    std::string extension = fs::extension(session.filepath);
-    session.lvbitx        = (extension == ".lvbitx");
+    const std::string extension = fs::path(session.filepath).extension().string();
+    session.lvbitx              = (extension == ".lvbitx");
 
     if (session.lvbitx) {
         extract_from_lvbitx(session);
