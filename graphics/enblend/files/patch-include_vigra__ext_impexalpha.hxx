# HG changeset patch
# User Chris <cspiel@users.sourceforge.net>
# Date 1453651551 -3600
# Node ID 467a73754dbb0e269f1b515bc2ef6664ab328bfa
# Parent  6aec0cc8d22a6fa617f983e676df68d75ffabbcf
Fix issue #1537368: Unconditional usage of std::auto_ptr<>
in "vigra_ext" code.

diff -r 6aec0cc8d22a -r 467a73754dbb include/vigra_ext/impexalpha.hxx
--- include/vigra_ext/impexalpha.hxx.orig	2015-08-07 14:45:05 UTC
+++ include/vigra_ext/impexalpha.hxx
@@ -26,6 +26,9 @@
 #include <vigra/imageinfo.hxx>
 #include <vigra/impex.hxx>
 
+#ifndef VIGRA_UNIQUE_PTR
+#define VIGRA_UNIQUE_PTR std::auto_ptr
+#endif
 
 namespace vigra_ext
 {
@@ -194,7 +197,7 @@ namespace vigra_ext
                          AlphaIterator alpha_iterator, AlphaAccessor alpha_accessor,
                          vigra::VigraTrueType)
         {
-            std::auto_ptr<vigra::Decoder> decoder(vigra::decoder(import_info));
+            VIGRA_UNIQUE_PTR<vigra::Decoder> decoder(vigra::decoder(import_info));
 
             switch (pixel_t_of_string(decoder->getPixelType()))
             {
@@ -249,7 +252,7 @@ namespace vigra_ext
                          AlphaIterator alpha_iterator, AlphaAccessor alpha_accessor,
                          vigra::VigraFalseType)
         {
-            std::auto_ptr<vigra::Decoder> decoder(vigra::decoder(import_info));
+            VIGRA_UNIQUE_PTR<vigra::Decoder> decoder(vigra::decoder(import_info));
 
             switch (pixel_t_of_string(decoder->getPixelType()))
             {
@@ -467,7 +470,7 @@ namespace vigra_ext
                          vigra::VigraTrueType)
         {
             const std::string pixel_type(export_info.getPixelType());
-            std::auto_ptr<vigra::Encoder> encoder(vigra::encoder(export_info));
+            VIGRA_UNIQUE_PTR<vigra::Encoder> encoder(vigra::encoder(export_info));
 
             encoder->setPixelType(pixel_type);
 
@@ -525,7 +528,7 @@ namespace vigra_ext
                          vigra::VigraFalseType)
         {
             const std::string pixel_type(export_info.getPixelType());
-            std::auto_ptr<vigra::Encoder> encoder(vigra::encoder(export_info));
+            VIGRA_UNIQUE_PTR<vigra::Encoder> encoder(vigra::encoder(export_info));
 
             encoder->setPixelType(pixel_type);
 
