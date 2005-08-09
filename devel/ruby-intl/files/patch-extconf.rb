--- extconf.rb.orig	Wed Aug 25 00:32:00 1999
+++ extconf.rb	Tue Aug  9 17:20:04 2005
@@ -4,6 +4,6 @@
 $CFLAGS = "-I/usr/local/include";
 have_library( "xpg4", "setlocale" );
 have_header( "locale.h" );
-if ( have_header( "libintl.h" ) and (have_library( "intl", "gettext" ) or have_func( "gettext" )) )
+if ( have_header( "libintl.h" ) and (have_library( "intl", "gettext" , "libintl.h" ) or have_func( "gettext" )) )
     create_makefile( "intl" );
 end
