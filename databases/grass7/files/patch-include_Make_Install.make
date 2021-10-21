--- include/Make/Install.make.orig	2021-10-17 18:22:04 UTC
+++ include/Make/Install.make
@@ -37,7 +37,6 @@ ifeq ($(strip $(MACOSX_APP)),1)
 	$(MAKE) install-macosx
 else
 	$(MAKE) install-check-parent
-	$(MAKE) install-check-writable
 	$(MAKE) install-check-prefix
 	$(MAKE) real-install
 endif
@@ -54,22 +53,7 @@ install-check-parent: | $(DESTDIR)
 	while [ ! -d "$(DESTDIR)$$INST_PATH" ]; do \
 		INST_PATH=`dirname $$INST_PATH`; \
 	done; \
-	if [ ! -d "$(DESTDIR)$(INST_DIR)" -a ! -w "$(DESTDIR)$$INST_PATH" ] ; then \
-		echo "ERROR: Directory $$INST_PATH is a parent directory of your" >&2 ; \
-		echo "  install directory $(INST_DIR) and is not writable." >&2 ; \
-		echo "  Perhaps you need root access." >&2 ; \
-		echo "  Installation aborted, exiting Make." >&2 ; \
-		exit 1; \
-	fi
 
-install-check-writable:
-	@ if [ -d "$(DESTDIR)$(INST_DIR)" -a ! -w "$(DESTDIR)$(INST_DIR)" ] ; then \
-		echo "ERROR: Your install directory $(INST_DIR) is not writable." >&2 ; \
-		echo "  Perhaps you need root access." >&2 ; \
-		echo "  Installation aborted, exiting Make." >&2 ; \
-		exit 1; \
-	fi
-
 install-check-prefix:
 	@ result=`echo "$(DESTDIR)$(INST_DIR)" | awk '{ if ($$1 ~ /grass/) print $$1 }'`; \
 	if [ "$$result" = "" ] ; then \
@@ -77,12 +61,6 @@ install-check-prefix:
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
