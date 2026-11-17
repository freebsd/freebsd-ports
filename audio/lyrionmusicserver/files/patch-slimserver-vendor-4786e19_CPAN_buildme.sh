--- ../slimserver-vendor-4786e19/CPAN/buildme.sh.orig	2026-05-20 04:00:45 UTC
+++ ../slimserver-vendor-4786e19/CPAN/buildme.sh
@@ -585,11 +585,11 @@ function build_all {
 #   build DBD::mysql
     build DBD::SQLite
     build Digest::SHA1
-    build EV
+    # build EV
     build Encode::Detect
     build HTML::Parser
     # XXX - Image::Scale requires libjpeg-turbo - which requires nasm 2.07 or later (install from http://www.macports.org/)
-    build Image::Scale
+#    build Image::Scale
     build IO::AIO
     build IO::Interface
 #   build IO::Socket::SSL
