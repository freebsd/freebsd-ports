--- extconf.rb.orig	2006-04-15 07:52:37.000000000 +1000
+++ extconf.rb	2008-05-29 12:54:28.000000000 +1000
@@ -2,8 +2,8 @@
 
 dir_config('frontbase')
 
-$CPPFLAGS = "-I/Library/FrontBase/include"
-$LDFLAGS = "-L/Library/FrontBase/lib"
+$CPPFLAGS = "-I/usr/local/include"
+$LDFLAGS = "-L/usr/local/lib"
 $libs = " -lFBCAccess "
 create_makefile("frontbase")
 
