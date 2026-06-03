--- default.mk.orig	2026-04-19 21:38:08 UTC
+++ default.mk
@@ -28,6 +28,8 @@ EMACS_ORG   ?= $(EMACS) $(EMACS_Q_ARG) --batch $(EMACS
 EMACS_BATCH ?= $(EMACS) $(EMACS_Q_ARG) --batch $(EMACS_ARGS) $(LOAD_PATH)
 EMACS_ORG   ?= $(EMACS) $(EMACS_Q_ARG) --batch $(EMACS_ARGS) $(ORG_LOAD_PATH)
 
+SED         ?= sed
+
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref https://magit.vc/assets/page.css
