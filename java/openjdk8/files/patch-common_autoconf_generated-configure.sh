--- common/autoconf/generated-configure.sh.orig	2022-11-10 08:32:52 UTC
+++ common/autoconf/generated-configure.sh
@@ -55202,7 +55202,7 @@ fi
   printf "A new configuration has been successfully created in\n"
   printf "$OUTPUT_ROOT\n"
   if test "x$CONFIGURE_COMMAND_LINE" != x; then
-    printf "using configure arguments '$CONFIGURE_COMMAND_LINE'.\n"
+    printf "using configure arguments '%s'.\n" "$CONFIGURE_COMMAND_LINE"
   else
     printf "using default settings.\n"
   fi
