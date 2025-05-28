--- make/autoconf/help.m4.orig	2025-05-24 21:54:30 UTC
+++ make/autoconf/help.m4
@@ -269,7 +269,7 @@ AC_DEFUN_ONCE([HELP_PRINT_SUMMARY_AND_WARNINGS],
     fi
   fi
   if test "x$CONFIGURE_COMMAND_LINE" != x; then
-    printf "using configure arguments '$CONFIGURE_COMMAND_LINE'.\n"
+    printf "using configure arguments '%s'.\n" "$CONFIGURE_COMMAND_LINE"
   else
     printf "using default settings.\n"
   fi
