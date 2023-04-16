--- common/autoconf/help.m4.orig	2022-11-10 08:32:46 UTC
+++ common/autoconf/help.m4
@@ -183,7 +183,7 @@ AC_DEFUN_ONCE([HELP_PRINT_SUMMARY_AND_WARNINGS],
   printf "A new configuration has been successfully created in\n"
   printf "$OUTPUT_ROOT\n"
   if test "x$CONFIGURE_COMMAND_LINE" != x; then
-    printf "using configure arguments '$CONFIGURE_COMMAND_LINE'.\n"
+    printf "using configure arguments '%s'.\n" "$CONFIGURE_COMMAND_LINE"
   else
     printf "using default settings.\n"
   fi
