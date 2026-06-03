--- ../slimserver-vendor-b62107b/CPAN/buildme.sh.orig	2026-01-11 22:49:42 UTC
+++ ../slimserver-vendor-b62107b/CPAN/buildme.sh
@@ -585,7 +585,7 @@ function build_all {
 #   build DBD::mysql
     build DBD::SQLite
     build Digest::SHA1
-    build EV
+    # build EV
     build Encode::Detect
     build HTML::Parser
     # XXX - Image::Scale requires libjpeg-turbo - which requires nasm 2.07 or later (install from http://www.macports.org/)
