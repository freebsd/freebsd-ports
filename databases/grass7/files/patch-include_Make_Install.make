--- include/Make/Install.make.orig	2016-11-04 UTC
+++ include/Make/Install.make
@@ -37,7 +37,6 @@ ifeq ($(strip $(MACOSX_APP)),1)
 	$(MAKE) install-macosx
 else
 	$(MAKE) install-check-parent
-	$(MAKE) install-check-writable
 	$(MAKE) install-check-prefix
 	$(MAKE) real-install
 endif
@@ -54,21 +53,6 @@ install-check-parent:
 	while [ ! -d "$$INST_PATH" ]; do \
 		INST_PATH=`dirname $$INST_PATH`; \
 	done; \
-	if [ ! -d "$(INST_DIR)" -a ! -w "$$INST_PATH" ] ; then \
-		echo "ERROR: Directory $$INST_PATH is a parent directory of your" >&2 ; \
-		echo "  install directory $(INST_DIR) and is not writable." >&2 ; \
-		echo "  Perhaps you need root access." >&2 ; \
-		echo "  Installation aborted, exiting Make." >&2 ; \
-		exit 1; \
-	fi
-
-install-check-writable:
-	@ if [ -d "$(INST_DIR)" -a ! -w "$(INST_DIR)" ] ; then \
-		echo "ERROR: Your install directory $(INST_DIR) is not writable." >&2 ; \
-		echo "  Perhaps you need root access." >&2 ; \
-		echo "  Installation aborted, exiting Make." >&2 ; \
-		exit 1; \
-	fi
 
 install-check-prefix:
 	@ result=`echo "$(INST_DIR)" | awk '{ if ($$1 ~ /grass/) print $$1 }'`; \
@@ -77,18 +61,12 @@ install-check-prefix:
 		echo "  does not contain the word 'grass'." >&2 ; \
 		echo "  It is highly recommended that the word 'grass' be part" >&2 ; \
 		echo "  of your install directory to avoid conflicts." >&2 ; \
-		echo "  Do you want to continue? [y/n]" >&2 ; \
-		read ans; \
-		if [ "$$ans" != "y" -a "$$ans" != "Y" ] ; then \
-			echo "Installation aborted, exiting Make." >&2 ; \
-			exit 1; \
-		fi; \
 	fi
 
 ifneq ($(strip $(MINGW)),)
 STARTUP = $(INST_DIR)/etc/$(GRASS_NAME).py
 else
-STARTUP = $(UNIX_BIN)/$(GRASS_NAME)
+STARTUP = ${DESTDIR}/$(UNIX_BIN)/$(GRASS_NAME)
 endif
 
 FONTCAP = etc/fontcap
@@ -96,7 +96,8 @@ TMPGISRC = demolocation/.grassrc$(GRASS_
 PLATMAKE = include/Make/Platform.make
 GRASSMAKE = include/Make/Grass.make
 
-real-install: | $(INST_DIR) $(UNIX_BIN)
+real-install: 
+	test -d $(INST_DIR) || $(MAKE_DIR_CMD) $(INST_DIR)
 	-tar cBCf $(GISBASE) - . | tar xBCf $(INST_DIR) - 2>/dev/null
 	-rm $(INST_DIR)/$(GRASS_NAME).tmp
 	$(MAKE) $(STARTUP)
@@ -121,8 +105,8 @@ ifneq ($(findstring darwin,$(ARCH)),)
 	@/bin/ln -sfh "$(INST_DIR)/docs/html" /Library/Documentation/Help/GRASS-$(GRASS_VERSION_MAJOR).$(GRASS_VERSION_MINOR)
 endif
 
-$(INST_DIR) $(UNIX_BIN):
-	$(MAKE_DIR_CMD) $@
+#$(INST_DIR) $(UNIX_BIN):
+#	$(MAKE_DIR_CMD) $@
 
 $(STARTUP): $(ARCH_DISTDIR)/$(GRASS_NAME).tmp
 	sed -e 's#'@GISBASE@'#'$(INST_DIR)'#g' \
