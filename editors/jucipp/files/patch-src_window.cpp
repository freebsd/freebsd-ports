--- src/window.cpp.orig	2023-08-03 07:43:31 UTC
+++ src/window.cpp
@@ -995,7 +995,7 @@ void Window::set_menu_actions() {
         if(std::any_of(exclude_folders.begin(), exclude_folders.end(), [&filename](const std::string &exclude_folder) {
              return filename == exclude_folder;
            }))
-          it.no_push();
+          it.disable_recursion_pending();
         continue;
       }
       files.emplace_back(path);
