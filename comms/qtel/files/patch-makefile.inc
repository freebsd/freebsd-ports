--- ../svxlink-11.05.orig/makefile.inc	2011-03-01 16:11:17.000000000 -0800
+++ makefile.inc	2012-05-28 10:27:56.000000000 -0700
@@ -43,6 +43,8 @@
 BIN		:= $(ROOT)/$(BIN)
 RPM_DIR       	:= $(ROOT)/$(RPM_DIR)
 
+vpath %.h $(INC) %%LOCALBASE%%/include %%LOCALBASE%%/include/tcl8.5
+
 # Path used by gcc to find library/include files. If you want to add a path
 # to the list. Use a "+=" after including this file.
 #   Ex. LIBPATH += /usr/X11R6/lib
@@ -162,7 +164,7 @@
 	    else \
 	      $(ECHO) --- Installing $(BOLD)$$file$(NBOLD) in \
 	              $(BOLD)$${target_dir}$(NBOLD)...; \
-	      cp -pdf $$file $${target_dir}; \
+	      cp -pf $$file $${target_dir}; \
 	      [ -n "$$perm" -a "$$perm" != '-' ] \
 	          && chmod $$perm $${target_dir}/`basename $$file`; \
 	      [ -z "$$NO_CHOWN" -a -n "$$owner" -a "$$owner" != '-' ] \
