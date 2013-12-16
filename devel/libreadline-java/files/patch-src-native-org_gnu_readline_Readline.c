--- src/native/org_gnu_readline_Readline.c.orig	2003-01-07 11:14:35.000000000 +0100
+++ src/native/org_gnu_readline_Readline.c	2013-12-12 20:40:36.000000000 +0100
@@ -430,7 +430,7 @@
   jtext = (*jniEnv)->NewStringUTF(jniEnv,text);
 
   if (jniMethodId == 0) {
-    return;
+    return 0;
   }
 
   completion = (*jniEnv)->CallObjectMethod(jniEnv, jniObject,
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
 
