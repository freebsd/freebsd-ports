--- makefile.inc.orig	2014-04-10 04:44:46.000000000 -0700
+++ makefile.inc	2014-04-10 04:45:04.000000000 -0700
@@ -160,7 +160,7 @@
 	    else \
 	      $(ECHO) --- Installing $(BOLD)$$file$(NBOLD) in \
 	              $(BOLD)$${target_dir}$(NBOLD)...; \
-	      cp -pdf $$file $${target_dir}; \
+	      cp -pf $$file $${target_dir}; \
 	      [ -n "$$perm" -a "$$perm" != '-' ] \
 	          && chmod $$perm $${target_dir}/`basename $$file`; \
 	      [ -z "$$NO_CHOWN" -a -n "$$owner" -a "$$owner" != '-' ] \
@@ -245,7 +245,7 @@
 	    target_dir=$${dir}; \
 	  fi; \
 	  if [ "$@" = "install-extras" ]; then \
-	    $(MKDIR) $${target_dir} -p; \
+	    $(MKDIR) -p $${target_dir}; \
 	    [ -n "$$perm" -a "$$perm" != '-' ] \
 	        && chmod $$perm $${target_dir}; \
 	    [ -z "$$NO_CHOWN" -a -n "$$owner" -a "$$owner" != '-' ] \
@@ -311,10 +311,10 @@
      }; remove_file
 
 # Some useful printing macros
-BOLD		= "\033[1m"
-NBOLD		= "\033[0m"
+#BOLD		= "\033[1m"
+#NBOLD		= "\033[0m"

 #ECHO		= /bin/echo -e
 BECHO		= $(ECHO) $(BOLD)txt $(NBOLD)
 
 # Compiler
@@ -408,7 +408,7 @@
 ifdef PROGS
 $(PROGS):	$(notdir $(PROGS:%=%.o)) $(PRGOBJS) $(LIBDEP)
 	if [ -n "$(BIN)" -a ! -d "$(BIN)" ]; then \
-	  $(MKDIR) $(BIN) -p; \
+	  $(MKDIR) -p $(BIN); \
 	fi
 	BASENAME=`basename $@`_version; \
 	if [ -r $${BASENAME}.h -a -r $${BASENAME}.c ]; then \
@@ -429,7 +429,7 @@
 ifdef CPPPROGS
 $(CPPPROGS):	$(notdir $(CPPPROGS:%=%.o)) $(PRGOBJS) $(LIBDEP)
 	if [ -n "$(BIN)" -a ! -d "$(BIN)" ]; then \
-	  $(MKDIR) $(BIN) -p; \
+	  $(MKDIR) -p $(BIN); \
 	fi
 	BASENAME=`basename $@`_version; \
 	if [ -r $${BASENAME}.h -a -r $${BASENAME}.c ]; then \
@@ -522,7 +522,7 @@
 $(EXPINC:%=$(INC)/%):
 	$(ECHO) --- Creating $(BOLD)$@$(NBOLD)...
 	if [ -n "$(INC)" -a ! -d "$(INC)" ]; then \
-	  $(MKDIR) $(INC) -p; \
+	  $(MKDIR) -p $(INC); \
 	fi
 	$(RM) $@
 	ln -s $$($(REVPATH) $$(dirname $@))/$$(basename $@) $@
@@ -535,7 +535,7 @@
 	$(RM) $(LIBFILE)
 	$(ECHO) --- Creating archive $(BOLD)$@$(NBOLD)...
 	if [ -n "$(LIB)" -a ! -d "$(LIB)" ]; then \
-	  $(MKDIR) $(LIB) -p; \
+	  $(MKDIR) -p $(LIB); \
       	fi
 	$(AR) cq $(LIBFILE) $(LIBOBJS)
 	if [ -n "$(STATIC_LIBS)" ]; then \
@@ -801,12 +801,12 @@
 endif
 
 $(ROOT)/.config:	$(ROOT)/create_config.sh
 	echo -e --- Creating $(BOLD)$@$(NBOLD)...
 	$(ROOT)/create_config.sh $@
 
 .config:
 	if [ -x ./create_config ]; then \
 	  echo -e --- Creating $(BOLD)$@$(NBOLD)...; \
 	  rm -f $@; \
 	  ./create_config $@; \
 	  echo "MAKEFILE_LOCAL_CONFIG_INCLUDED = 1" >> $@; \
@@ -815,7 +815,7 @@
 # Generate version files
 version/%.h: $(ROOT)/versions
 	if [ ! -d version ]; then \
-	  $(MKDIR) version -p; \
+	  $(MKDIR) -p version; \
 	fi; \
 	. $(ROOT)/versions; \
 	if [ -n "$${$*}" ]; then \
