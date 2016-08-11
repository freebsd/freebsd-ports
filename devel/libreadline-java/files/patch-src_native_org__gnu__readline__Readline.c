--- src/native/org_gnu_readline_Readline.c.orig	2003-01-07 10:14:35 UTC
+++ src/native/org_gnu_readline_Readline.c
@@ -430,7 +430,7 @@ const char *java_completer(char *text, i
   jtext = (*jniEnv)->NewStringUTF(jniEnv,text);
 
   if (jniMethodId == 0) {
-    return;
+    return 0;
   }
 
   completion = (*jniEnv)->CallObjectMethod(jniEnv, jniObject,
@@ -560,6 +560,21 @@ JNIEXPORT void JNICALL 
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
 
