--- extconf.rb.orig	Mon Apr 23 21:31:46 2001
+++ extconf.rb	Sun Jun  3 03:44:04 2001
@@ -1,11 +1,7 @@
 require 'mkmf'
 
-# You may need to change these parameters
-FREETDSDIR = "/usr/local/freetds"
-# end of parameters
+dir_config("freetds", "/usr/local/freetds")
 
-$CFLAGS = "-I#{FREETDSDIR}/include"
-$LDFLAGS = "-L#{FREETDSDIR}/lib"
 $libs = "-ltds"
 
-create_makefile("dbd_sybase")
+create_makefile("dbd_sybase")
