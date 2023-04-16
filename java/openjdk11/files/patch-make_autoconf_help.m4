--- make/autoconf/help.m4.orig	2023-01-20 14:03:22 UTC
+++ make/autoconf/help.m4
@@ -238,7 +238,7 @@ AC_DEFUN_ONCE([HELP_PRINT_SUMMARY_AND_WARNINGS],
     fi
   fi
   if test "x$CONFIGURE_COMMAND_LINE" != x; then
-    printf "using configure arguments '$CONFIGURE_COMMAND_LINE'.\n"
+    printf "using configure arguments '%s'.\n" "$CONFIGURE_COMMAND_LINE"
   else
     printf "using default settings.\n"
   fi
