--- extconf.rb.orig	Mon Jan 15 13:37:15 2001
+++ extconf.rb	Wed Feb  7 14:53:24 2001
@@ -20,7 +20,7 @@
 
 $CFLAGS += ' -I. -O -w '
 
-if have_header('qapplication.h') and have_header('qgl.h') and have_library('qt','qGLVersion__Fv')
+if have_header('qapplication.h') and have_header('qgl.h') and have_library(qt2,'qGLVersion__Fv')
   create_makefile('qt2gl')
 else
   print "You do not seem to have qt(+qgl) library. Plrease check qt or extconf.rb.\n"
