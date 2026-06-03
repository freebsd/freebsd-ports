--- default.mk.orig	2026-05-10 01:05:21 UTC
+++ default.mk
@@ -25,6 +25,8 @@ EMACS_INTR  ?= $(EMACS) $(EMACS_Q_ARG) $(EMACS_ARGS) $
 EMACS_ORG   ?= $(EMACS) $(EMACS_Q_ARG) --batch $(EMACS_ARGS) $(ORG_LOAD_PATH)
 EMACS_INTR  ?= $(EMACS) $(EMACS_Q_ARG) $(EMACS_ARGS) $(LOAD_PATH)
 
+SED         ?= sed
+
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref https://magit.vc/assets/page.css
