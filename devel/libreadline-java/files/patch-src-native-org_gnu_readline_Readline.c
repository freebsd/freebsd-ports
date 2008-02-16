--- src/native/org_gnu_readline_Readline.c.orig	2003-01-07 11:14:35.000000000 +0100
+++ src/native/org_gnu_readline_Readline.c	2007-09-27 09:21:14.000000000 +0200
@@ -560,6 +560,21 @@
 #endif
 
 /* -------------------------------------------------------------------------- */
+/* Sets/gets rl_completion_append_character                                   */
+/* -------------------------------------------------------------------------- */
+
+#ifndef JavaGetline
+JNIEXPORT jchar JNICALL
+Java_org_gnu_readline_Readline_setCompletionAppendCharacterImpl
+(JNIEnv * env, jclass class, jchar appendCharacter) {
+	int previous_setting = rl_completion_append_character;
+
+	rl_completion_append_character = (int)appendCharacter;
+	return (jchar)previous_setting;
+}
+#endif
+
+/* -------------------------------------------------------------------------- */
 /* Convert utf8-string to ucs1-string                   .                     */
 /* -------------------------------------------------------------------------- */
 
