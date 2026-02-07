--- make/mksh/dosys.cc.orig	2007-03-07 00:12:07 UTC
+++ make/mksh/dosys.cc
@@ -99,6 +99,9 @@
 /*
  * typedefs & structs
  */
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif /* __FreeBSD__ */
 
 /*
  * Static variables
@@ -809,7 +812,7 @@ sh_command2string(register String command, register St
 	int			status;
 	Boolean			command_generated_output = false;
 
-	command->text.p = (int) nul_char;
+	command->text.p[0] = (int) nul_char;
 	WCSTOMBS(mbs_buffer, command->buffer.start);
 	if ((fd = popen(mbs_buffer, "r")) == NULL) {
 		WCSTOMBS(mbs_buffer, command->buffer.start);
