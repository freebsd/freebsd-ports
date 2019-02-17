--- TuxGuitar-fluidsynth/jni/org_herac_tuxguitar_player_impl_midiport_fluidsynth_MidiSynth.c.orig	2009-10-31 14:34:13 UTC
+++ TuxGuitar-fluidsynth/jni/org_herac_tuxguitar_player_impl_midiport_fluidsynth_MidiSynth.c
@@ -16,7 +16,11 @@ typedef struct{
 	jobject options;
 }fluid_settings_foreach_option_data;
 
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 void fluid_settings_foreach_option_callback(void *data, char *name, char *option)
+#else
+void fluid_settings_foreach_option_callback(void *data, const char *name, const char *option)
+#endif
 {
 	fluid_settings_foreach_option_data* handle = (fluid_settings_foreach_option_data *)data;
 	
@@ -255,8 +259,12 @@ JNIEXPORT void JNICALL Java_org_herac_tuxguitar_player
 			jstring jvalue = NULL;
 			char *value = NULL;
 			const jbyte *jkey = (*env)->GetStringUTFChars(env, key, NULL);
-			
+
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 			fluid_settings_getstr(handle->settings,(char *)jkey, &value );
+#else
+			fluid_settings_dupstr(handle->settings,(char *)jkey, &value );
+#endif
 			jvalue = (*env)->NewStringUTF(env, value);
 			
 			(*env)->ReleaseStringUTFChars(env, key, jkey);
@@ -274,7 +282,12 @@ JNIEXPORT void JNICALL Java_org_herac_tuxguitar_player
 		jmethodID mid = (*env)->GetMethodID(env, cl, "setValue", "(D)V");
 		if (mid != 0){
 			const jbyte *jkey = (*env)->GetStringUTFChars(env, key, NULL);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 			double value = fluid_settings_getnum_default(handle->settings,(char *)jkey);
+#else
+			double value = 0.0;
+			fluid_settings_getnum_default(handle->settings, (char*)jkey, &value);
+#endif
 			
 			(*env)->ReleaseStringUTFChars(env, key, jkey);
 			(*env)->CallVoidMethod( env, ref , mid , (jdouble)value );
@@ -291,7 +304,12 @@ JNIEXPORT void JNICALL Java_org_herac_tuxguitar_player
 		jmethodID mid = (*env)->GetMethodID(env, cl, "setValue", "(I)V");
 		if (mid != 0){
 			const jbyte *jkey = (*env)->GetStringUTFChars(env, key, NULL);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 			int value = fluid_settings_getint_default(handle->settings,(char *)jkey);
+#else
+			int value = 0;
+			fluid_settings_getint_default(handle->settings,(char *)jkey, &value);
+#endif
 			
 			(*env)->ReleaseStringUTFChars(env, key, jkey);
 			(*env)->CallVoidMethod( env, ref , mid , (jint)value );
@@ -308,7 +326,12 @@ JNIEXPORT void JNICALL Java_org_herac_tuxguitar_player
 		jmethodID mid = (*env)->GetMethodID(env, cl, "setValue", "(Ljava/lang/String;)V");
 		if (mid != 0){
 			const jbyte *jkey = (*env)->GetStringUTFChars(env, key, NULL);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 			char *value = fluid_settings_getstr_default(handle->settings,(char *)jkey);
+#else
+			char *value = NULL;
+			fluid_settings_getstr_default(handle->settings,(char *)jkey, &value);
+#endif
 			jstring jvalue = (*env)->NewStringUTF(env, value);
 			
 			(*env)->ReleaseStringUTFChars(env, key, jkey);
