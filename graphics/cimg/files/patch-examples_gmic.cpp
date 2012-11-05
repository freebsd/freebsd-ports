--- examples/gmic.cpp.orig	2012-10-15 17:31:08.000000000 +0200
+++ examples/gmic.cpp	2012-11-05 18:29:29.000000000 +0100
@@ -10776,7 +10776,7 @@
       *const command = is_help1?is_help1:is_help2?is_help2:is_help3?is_help3:is_help4;
     if (!std::strcmp(is_help,command)) gmic("-v - -help",images,images_names); // Global help.
     else { // Help for a specified command.
-      std::snprintf(command_line,sizeof(command_line),"-v - -help \"%s\",1",command);
+      snprintf(command_line,sizeof(command_line),"-v - -help \"%s\",1",command);
       gmic(command_line,images,images_names);
     }
     std::exit(0);
@@ -10796,7 +10796,7 @@
                    e.command());
       images.assign(); images_names.assign();
       CImg<unsigned char>(data_gmic_def,1,size_data_gmic_def,1,1).move_to(images);
-      std::snprintf(command_line,sizeof(command_line),"-v - -help \"%s\",0",e.command());
+      snprintf(command_line,sizeof(command_line),"-v - -help \"%s\",0",e.command());
       gmic(command_line,images,images_names);
     } else { std::fprintf(cimg::output(),"\n\n"); std::fflush(cimg::output()); }
     return -1;
