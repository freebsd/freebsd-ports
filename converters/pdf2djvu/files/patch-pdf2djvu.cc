--- pdf2djvu.cc.orig	2013-05-30 22:22:26.000000000 +0200
+++ pdf2djvu.cc	2013-10-19 16:11:38.078951359 +0200
@@ -212,7 +212,7 @@
 
 Command &operator <<(Command &command, const Component &component)
 {
-  command << *component.file;
+  command << std::string(*component.file);
   return command;
 }
 
@@ -980,7 +980,7 @@
   {
     debug(3) << _("creating document outline with `djvused`") << std::endl;
     DjVuCommand djvused("djvused");
-    djvused << "-s" << "-f" << outlines_sed_file << this->index_file;
+    djvused << "-s" << "-f" << std::string(outlines_sed_file) << std::string(this->index_file);
     djvused(); // djvused -s -f <outlines-sed-file> <index-djvu-file>
   }
 
@@ -991,7 +991,7 @@
     {
       debug(3) << _("setting metadata with `djvused`") << std::endl;
       DjVuCommand djvused("djvused");
-      djvused << "-s" << "-f" << metadata_sed_file << this->index_file;
+      djvused << "-s" << "-f" << std::string(metadata_sed_file) << std::string(this->index_file);
       djvused(); // djvused -s -f <metadata-sed-file> <index-djvu-file>
     }
     else
@@ -1025,7 +1025,7 @@
         dummy_components.push_back(this->components[i]);
         this->do_create(dummy_components);
         DjVuCommand djvused("djvused");
-        djvused << "-s" << "-f" << dummy_sed_file << this->index_file;
+        djvused << "-s" << "-f" << std::string(dummy_sed_file) << std::string(this->index_file);
         djvused(); // djvused -s -f <dummy-sed-file> <output-djvu-file>
         dummy_components.pop_back();
       }
@@ -1033,7 +1033,7 @@
       dummy_components.push_back(this->components[size - 1]);
       this->do_create(dummy_components);
       DjVuCommand djvused("djvused");
-      djvused << "-s" << "-f" << metadata_sed_file << this->index_file;
+      djvused << "-s" << "-f" << std::string(metadata_sed_file) << std::string(this->index_file);
       djvused(); // djvused -s -f <metadata-sed-file> <output-djvu-file>
       /* Finally, recreate the index. */
       this->do_create(this->components, true /* include shared annotations */);
@@ -1089,8 +1089,8 @@
 {
   this->converter
     << "-b"
-    << *this->index_file
-    << this->output_file;
+    << std::string(*this->index_file)
+    << std::string(this->output_file);
   this->converter(); // djvmcvt -b <output-djvu-file> <index-djvu-file>
   this->index_file.reset(NULL);
 }
@@ -1122,7 +1122,7 @@
     }
     bzz_file.close();
     DjVuCommand bzz("bzz");
-    bzz << "-e" << bzz_file << "-";
+    bzz << "-e" << std::string(bzz_file) << "-";
     bzz(index_file);
   }
   size = this->index_file.size();
@@ -1498,7 +1498,7 @@
         csepdjvu << "-q" << config.bg_slices;
       if (config.text == config.TEXT_LINES)
         csepdjvu << "-t";
-      csepdjvu << sep_file << component;
+      csepdjvu << std::string(sep_file) << component;
       csepdjvu();
     }
     const bool should_have_fgbz = has_background || has_foreground || nonwhite_background_color;
@@ -1528,7 +1528,7 @@
         TemporaryFile pbm_file;
         debug(3) << _("encoding monochrome image with `cjb2`") << std::endl;
         DjVuCommand cjb2("cjb2");
-        cjb2 << "-losslevel" << config.loss_level << pbm_file << sjbz_file;
+        cjb2 << "-losslevel" << config.loss_level << std::string(pbm_file) << std::string(sjbz_file);
         pbm_file << "P4 " << width << " " << height << std::endl;
         pdf::Pixmap bmp(outm->has_skipped_elements() ? out1.get() : outm.get());
         pbm_file << bmp;
@@ -1543,7 +1543,7 @@
           TemporaryFile ppm_file;
           debug(3) << _("creating new background image with `c44`") << std::endl;
           DjVuCommand c44("c44");
-          c44 << "-slice" << "97" << ppm_file << c44_file;
+          c44 << "-slice" << "97" << std::string(ppm_file) << std::string(c44_file);
           int bg_width = (width + 11) / 12;
           int bg_height = (height + 11) / 12;
           ppm_file << "P6 " << bg_width << " " << bg_height << " 255" << std::endl;
@@ -1560,7 +1560,7 @@
         { /* Replace previous (dummy) BG44 chunk with the newly created one: */
           debug(3) << _("recovering image chunks with `djvuextract`") << std::endl;
           DjVuCommand djvuextract("djvuextract");
-          djvuextract << c44_file << std::string("BG44=") + std::string(bg44_file);
+          djvuextract << std::string(c44_file) << std::string("BG44=") + std::string(bg44_file);
           djvuextract(config.verbose < 3);
         }
       }
@@ -1601,7 +1601,7 @@
     { /* Add per-page non-raster data into the DjVu file: */
       debug(3) << _("adding non-raster data with `djvused`") << std::endl;
       DjVuCommand djvused("djvused");
-      djvused << component << "-s" << "-f" << sed_file;
+      djvused << component << "-s" << "-f" << std::string(sed_file);
       djvused();
     }
     {
