--- GDBM_File.pm.orig	2011-09-19 21:18:22.000000000 +0800
+++ GDBM_File.pm	2012-01-08 17:46:35.851999568 +0800
@@ -71,6 +71,6 @@
 # This module isn't dual life, so no need for dev version numbers.
 $VERSION = '1.14';
 
-XSLoader::load();
+XSLoader::load 'GDBM_File', $VERSION;
 
 1;
