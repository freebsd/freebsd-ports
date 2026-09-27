--- sys/unix/setup.sh.orig	2026-09-27 12:37:12 UTC
+++ sys/unix/setup.sh
@@ -32,7 +32,7 @@ esac
 esac
 
 # is make gnu or bsd?
-if make --version 2>/dev/null | grep -q "GNU"; then
+if $MAKE --version 2>/dev/null | grep -q "GNU"; then
     whichmake=gnu
 else
     whichmake=bsd
