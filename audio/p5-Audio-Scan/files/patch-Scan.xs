Fix Unparseable XSUB parameter: 'char *' in Scan.xs, line xxx

--- Scan.xs.orig	2025-07-13 08:30:15 UTC
+++ Scan.xs
@@ -214,7 +214,7 @@ HV *
 MODULE = Audio::Scan		PACKAGE = Audio::Scan
 
 HV *
-_scan( char *, char *suffix, PerlIO *infile, SV *path, int filter, int md5_size, int md5_offset )
+_scan( char * _unused, char *suffix, PerlIO *infile, SV *path, int filter, int md5_size, int md5_offset )
 CODE:
 {
   taghandler *hdl;
@@ -266,7 +266,7 @@ int
   RETVAL
   
 int
-_find_frame( char *, char *suffix, PerlIO *infile, SV *path, int offset )
+_find_frame( char * _unused, char *suffix, PerlIO *infile, SV *path, int offset )
 CODE:
 {
   taghandler *hdl;
@@ -282,7 +282,7 @@ HV *
   RETVAL
 
 HV *
-_find_frame_return_info( char *, char *suffix, PerlIO *infile, SV *path, int offset )
+_find_frame_return_info( char * _unused, char *suffix, PerlIO *infile, SV *path, int offset )
 CODE:
 {
   taghandler *hdl = _get_taghandler(suffix);
@@ -306,7 +306,7 @@ int
   RETVAL
 
 int
-is_supported(char *, SV *path)
+is_supported(char * _unused, SV *path)
 CODE:
 {
   char *suffix = strrchr( SvPVX(path), '.' );
@@ -322,7 +322,7 @@ SV *
   RETVAL
 
 SV *
-type_for(char *, SV *suffix)
+type_for(char * _unused, SV *suffix)
 CODE:
 {
   taghandler *hdl = NULL;
@@ -360,7 +360,7 @@ AV *
   RETVAL
 
 AV *
-extensions_for(char *, SV *type)
+extensions_for(char * _unused, SV *type)
 CODE:
 {
   int i, j;
