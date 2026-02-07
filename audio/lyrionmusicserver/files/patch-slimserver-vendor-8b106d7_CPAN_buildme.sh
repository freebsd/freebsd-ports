--- slimserver-vendor-8b106d7/CPAN/buildme.sh.orig	2025-09-22 10:04:42 UTC
+++ slimserver-vendor-8b106d7/CPAN/buildme.sh
@@ -576,32 +576,32 @@ function build_all {
 }
 
 function build_all {
-    build Audio::Scan
+#    build Audio::Scan
     build Class::C3::XS
-    build Class::XSAccessor
-    build Compress::Raw::Zlib
+#    build Class::XSAccessor
+    # build Compress::Raw::Zlib
     # DBD::SQLite builds DBI, so don't need it here as well.
 #   build DBI
 #   build DBD::mysql
-    build DBD::SQLite
-    build Digest::SHA1
-    build EV
-    build Encode::Detect
-    build HTML::Parser
+#    build DBD::SQLite
+#    build Digest::SHA1
+    # build EV
+    # build Encode::Detect
+#    build HTML::Parser
     # XXX - Image::Scale requires libjpeg-turbo - which requires nasm 2.07 or later (install from http://www.macports.org/)
-    build Image::Scale
-    build IO::AIO
-    build IO::Interface
+#    build Image::Scale
+#    build IO::AIO
+#    build IO::Interface
 #   build IO::Socket::SSL
-    build JSON::XS
+#    build JSON::XS
     build Linux::Inotify2
     build Mac::FSEvents
    #  build Media::Scan
     build MP3::Cut::Gapless
-    build Sub::Name
-    build Template
-    build XML::Parser
-    build YAML::LibYAML
+ #   build Sub::Name
+#    build Template
+#    build XML::Parser
+#    build YAML::LibYAML
 #    build Font::FreeType
 #    build Locale::Hebrew
 }
