--- Makefile.PL.orig	Wed Jun 20 08:39:13 2001
+++ Makefile.PL	Tue Dec 14 18:36:26 2004
@@ -17,7 +17,7 @@
 
 $pm_lib = (grep /^X11$/, @ARGV) ? '' : '-lopengl';
 
-$libs = "-lGLU -lGLUT -lGLX $pm_lib -lMesaGLU -lMesaGLUT -lMesaGLX -lglut";
+$libs = "-lglut %%PTHREAD_LIBS%%";
 
 @libs = findlib->ext("$libdirs $libs");
 
@@ -75,6 +75,11 @@
 
 $DEFS .= ' -DOS2_GL_DISABLE_MISSING_EXT -DAPIENTRY= -D__PM__'
   if $^O eq 'os2' and not $x;
+
+# Check for GL extensions header (glext.h)
+$glextout = `echo '\#include <GL/glext.h>' | $Config{cpprun} $includes $Config{cppflags} $Config{cppminus} >/dev/null 2>&1`;
+$no_glext = $?;
+$DEFS .= " -DHAVE_GLEXT_H" unless $no_glext;
 
 # Should be deduced automatically, but how?!
 $no_lgcc = (grep /^NO_LGCC$/, @ARGV);
