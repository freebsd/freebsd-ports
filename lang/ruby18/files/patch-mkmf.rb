--- lib/mkmf.rb.orig	Fri Apr 23 23:25:28 2004
+++ lib/mkmf.rb	Tue Jul 13 15:57:40 2004
@@ -670,7 +670,7 @@
     ldirs.concat(defaults.collect {|dir| dir + "/lib"})
     ldir = ([ldir] + ldirs).compact.join(File::PATH_SEPARATOR)
   end
-  $LIBPATH |= ldirs
+  $LIBPATH = ldirs | $LIBPATH
 
   [idir, ldir]
 end
@@ -969,8 +969,7 @@
   $LIBRUBYARG = ""
   $LIBRUBYARG_STATIC = config['LIBRUBYARG_STATIC']
   $LIBRUBYARG_SHARED = config['LIBRUBYARG_SHARED']
-  $LIBPATH = CROSS_COMPILING ? [] : ["$(libdir)"]
-  $LIBPATH.unshift("$(topdir)") if $extmk
+  $LIBPATH = $extmk ? ["$(topdir)"] : CROSS_COMPILING ? [] : ["$(libdir)"]
   $INSTALLFILES = nil
 
   $objs = nil
