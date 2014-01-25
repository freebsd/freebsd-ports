--- Make.mk.orig	2013-08-01 21:40:42.000000000 +0200
+++ Make.mk	2014-01-26 00:04:27.000000000 +0100
@@ -65,12 +65,12 @@ info := $(topics) $(subjects) all TOP
 scripts := $(srcdir)/src/scripts
 depcomp := $(SHELL) $(srcdir)/depcomp
 tarball := $(SHELL) -e $(scripts)/tarball
-econfig := $(sysconfdir)/empire/econfig
-schedule := $(sysconfdir)/empire/schedule
-gamedir := $(localstatedir)/empire
-builtindir := $(datadir)/empire/builtin
-einfodir := $(datadir)/empire/info.nr
-ehtmldir := $(datadir)/empire/info.html
+econfig := $(sysconfdir)/wolfpack/econfig
+schedule := $(sysconfdir)/wolfpack/schedule
+gamedir := $(localstatedir)/wolfpack
+builtindir := $(datadir)/wolfpack/builtin
+einfodir := $(datadir)/wolfpack/info.nr
+ehtmldir := $(datadir)/wolfpack/info.html
 client/w32 := arpa/inet.h netdb.h netinet/in.h sys/time.h sys/socket.h	\
 sys/uio.h unistd.h w32io.c w32sockets.c w32types.h
 
@@ -198,41 +198,41 @@ distclean: clean
 
 .PHONY: install
 install: all installdirs
-	$(INSTALL_PROGRAM) $(util) $(server) $(sbindir)
-	$(INSTALL_PROGRAM) $(client) $(bindir)
-	$(INSTALL) -m 444 $(addprefix $(srcdir)/, $(builtins)) $(builtindir)
-	$(INSTALL_DATA) $(info.nr) $(einfodir)
-	$(INSTALL_DATA) $(addprefix $(srcdir)/, $(man6)) $(mandir)/man6
-	sed -e '1,/^$$/d' -e 's/^/# /g' <$(srcdir)/doc/schedule >$(schedule).dist
-	echo >>$(schedule).dist
-	echo 'every 10 minutes' >>$(schedule).dist
-	[ -e $(schedule) ] || mv $(schedule).dist $(schedule)
-	if [ -e $(econfig) ]; then					\
+	$(INSTALL_PROGRAM) $(util) $(server) $(DESTDIR)$(sbindir)
+	$(INSTALL_PROGRAM) $(client) $(DESTDIR)$(bindir)
+	$(INSTALL) -m 444 $(addprefix $(srcdir)/, $(builtins)) $(DESTDIR)$(builtindir)
+	$(INSTALL_DATA) $(info.nr) $(DESTDIR)$(einfodir)
+	$(INSTALL_DATA) $(addprefix $(srcdir)/, $(man6)) $(DESTDIR)$(mandir)/man6
+	sed -e '1,/^$$/d' -e 's/^/# /g' <$(srcdir)/doc/schedule >$(DESTDIR)$(schedule).dist
+	echo >>$(DESTDIR)$(schedule).dist
+	echo 'every 10 minutes' >>$(DESTDIR)$(schedule).dist
+	[ -e $(DESTDIR)$(schedule) ] || mv $(DESTDIR)$(schedule).dist $(DESTDIR)$(schedule)
+	if [ -e $(DESTDIR)$(econfig) ]; then					\
 	    echo "Attempting to update your econfig";			\
-	    if src/util/pconfig $(econfig) >$(econfig).dist; then	\
-	        if cmp -s $(econfig) $(econfig).dist; then		\
+	    if src/util/pconfig $(DESTDIR)$(econfig) >$(DESTDIR)$(econfig).dist; then	\
+	        if cmp -s $(DESTDIR)$(econfig) $(DESTDIR)$(econfig).dist; then		\
 		    echo "$(econfig) unchanged";			\
-		    rm $(econfig).dist;					\
+		    rm $(DESTDIR)$(econfig).dist;					\
 		fi;							\
 	    else							\
 		echo "Your $(econfig) doesn't work";			\
-		src/util/pconfig >$(econfig).dist;			\
+		src/util/pconfig >$(DESTDIR)$(econfig).dist;			\
 	    fi;								\
-	    if [ -e $(econfig).dist ]; then				\
+	    if [ -e $(DESTDIR)$(econfig).dist ]; then				\
 		echo "Check out $(econfig).dist";			\
 	    fi;								\
 	else								\
-	    src/util/pconfig >$(econfig);				\
+	    src/util/pconfig >$(DESTDIR)$(econfig);				\
 	fi
 
 .PHONY: installdirs
 installdirs:
-	mkdir -p $(sbindir) $(bindir) $(builtindir) $(einfodir) $(mandir)/man6 $(dir $(econfig)) $(gamedir)
+	mkdir -p $(DESTDIR)$(sbindir) $(DESTDIR)$(bindir) $(DESTDIR)$(builtindir) $(DESTDIR)$(einfodir) $(DESTDIR)$(mandir)/man6 $(dir $(DESTDIR)$(econfig)) $(DESTDIR)$(gamedir)
 
 .PHONY: install-html
 install-html: html
-	mkdir -p $(ehtmldir)
-	$(INSTALL_DATA) $(info.html) $(ehtmldir)
+	mkdir -p $(DESTDIR)$(ehtmldir)
+	$(INSTALL_DATA) $(info.html) $(DESTDIR)$(ehtmldir)
 
 .PHONY: uninstall
 uninstall:
