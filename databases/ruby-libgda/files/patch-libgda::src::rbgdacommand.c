--- src/rbgdacommand.c.orig	Mon Apr 12 14:43:02 2004
+++ src/rbgdacommand.c	Mon Apr 12 14:45:53 2004
@@ -62,10 +62,11 @@
     int argc;
     VALUE *argv, self;
 {
+    GdaCommand *cmd;
     VALUE text, command_type, options;
 
     rb_scan_args(argc, argv, "21", &text, &command_type, &options);
-    GdaCommand *cmd = gda_command_new(RVAL2CSTR(text),
+    cmd = gda_command_new(RVAL2CSTR(text),
                                       RVAL2GENUM(command_type, GDA_TYPE_COMMAND_TYPE),
                                       NIL_P(options) ? GDA_COMMAND_OPTION_STOP_ON_ERRORS : RVAL2GFLAGS(options, GDA_TYPE_COMMAND_OPTIONS));
     if (cmd != NULL) {
