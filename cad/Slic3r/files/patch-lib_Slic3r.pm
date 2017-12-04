--- lib/Slic3r.pm.orig	2017-12-03 15:21:42 UTC
+++ lib/Slic3r.pm
@@ -30,7 +30,7 @@ warn "Running Slic3r under Perl 5.16 is not supported 
     if $^V == v5.16;
 
 use FindBin;
-our $var = decode_path($FindBin::Bin) . "/var";
+our $var = "%%DATADIR%%";
 
 use Moo 1.003001;
 
