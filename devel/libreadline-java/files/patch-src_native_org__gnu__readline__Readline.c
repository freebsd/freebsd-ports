--- src/native/org_gnu_readline_Readline.c.orig	2017-04-02 09:52:09 UTC
+++ src/native/org_gnu_readline_Readline.c
@@ -430,7 +430,7 @@ const char *java_completer(char *text, int state) {
   jtext = (*jniEnv)->NewStringUTF(jniEnv,text);
 
   if (jniMethodId == 0) {
-    return;
+    return 0;
   }
 
   completion = (*jniEnv)->CallObjectMethod(jniEnv, jniObject,
@@ -472,11 +472,7 @@ JNIEXPORT void JNICALL Java_org_gnu_readline_Readline_
       rl_completion_entry_function = NULL;
       return;
     }
-#ifdef JavaEditline
-    rl_completion_entry_function = (CPFunction *) java_completer;
-#else
     rl_completion_entry_function = (rl_compentry_func_t *) java_completer;
-#endif
   }
   else {
     rl_completion_entry_function = NULL;
@@ -556,6 +552,21 @@ JNIEXPORT void JNICALL 
     return;    
   }
   rl_completer_word_break_characters = word_break_buffer;
+}
+#endif
+
+/* -------------------------------------------------------------------------- */
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
 }
 #endif
 
