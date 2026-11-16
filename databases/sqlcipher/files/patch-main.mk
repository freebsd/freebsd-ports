--- main.mk.orig	2026-11-16 03:55:09 UTC
+++ main.mk
@@ -2251,7 +2251,7 @@ install-man1: $(install-dir.man1)
 #install: install-rsync
 
 install-man1: $(install-dir.man1)
-	$(INSTALL.noexec) "$(TOP)/sqlite3.1" "$(install-dir.man1)"
+	$(INSTALL.noexec) "$(TOP)/sqlcipher.1" "$(install-dir.man1)"
 install: install-man1
 
 #
