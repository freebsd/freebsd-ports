--- Makefile2.m4.orig	Wed Aug  6 22:34:47 1997
+++ Makefile2.m4	Wed Dec  6 15:35:00 2006
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
@@ -555,8 +555,6 @@
 # XXX make hard link from $(BINDEST) to $(BINDEST)-`./pv`??
 
 install: TESTED doc/snobol4.1
-	-rm -f $(BINDEST).old
-	-mv -f $(BINDEST) $(BINDEST).old
 	cp xsnobol4 $(BINDEST); strip $(BINDEST); chmod 755 $(BINDEST)
 	cp doc/snobol4.1 $(MANDEST)
 	test -d $(SNOLIB_DIR) || mkdir $(SNOLIB_DIR)
