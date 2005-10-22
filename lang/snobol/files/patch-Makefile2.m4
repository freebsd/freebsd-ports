--- Makefile2.m4.orig	Fri Oct 21 18:07:57 2005
+++ Makefile2.m4	Fri Oct 21 18:08:39 2005
@@ -48,13 +48,13 @@
 SNOLIB_FILE=snolib.a
 
 # directory name for default SNOLIB (used by -INCLUDE and LOAD())
-SNOLIB_DIR=/usr/local/lib/snobol4
+SNOLIB_DIR=${LOCALBASE}/lib/snobol4
 
 # default name for installed binary
-BINDEST=/usr/local/bin/snobol4
+BINDEST=${LOCALBASE}/bin/snobol4
 
 # default name for installed man page
-MANDEST=/usr/local/man/man1/snobol4.1
+MANDEST=${LOCALBASE}/man/man1/snobol4.1
 
 ########
 # default lib source files
