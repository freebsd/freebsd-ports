--- aclocal.m4.orig	Mon Jan 27 21:52:25 2003
+++ aclocal.m4	Mon Jan 27 21:52:56 2003
@@ -164,6 +164,7 @@
 
 # This can be used to rebuild libtool when needed
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+$ac_aux_dir/ltconfig $LIBTOOL_DEPS
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
