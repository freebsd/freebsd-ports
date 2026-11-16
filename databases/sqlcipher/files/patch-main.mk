--- main.mk.orig	2026-10-26 13:57:49 UTC
+++ main.mk
@@ -2307,7 +2307,7 @@ install-man1: $(install-dir.man1)
 #install: install-rsync
 
 install-man1: $(install-dir.man1)
-	$(INSTALL.noexec) "$(TOP)/sqlite3.1" "$(install-dir.man1)"
+	$(INSTALL.noexec) "$(TOP)/sqlcipher.1" "$(install-dir.man1)"
 install: install-man1
 
 #
