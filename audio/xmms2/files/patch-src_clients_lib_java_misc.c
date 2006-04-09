--- src/clients/lib/java/misc.c.orig	Mon Mar 27 11:34:45 2006
+++ src/clients/lib/java/misc.c	Sat Apr  8 00:27:56 2006
@@ -37,11 +37,12 @@
 }
 
 JNIEXPORT void JNICALL Java_org_xmms2_SpecialJNI_setENV(JNIEnv *jenv, jclass cls, jobject myobject){
+	jclass clazz;
 	globalObj = (*jenv)->NewGlobalRef(jenv, myobject);
 	if (jvm == NULL)
 		(*jenv)->GetJavaVM(jenv,&jvm);
 
-	jclass clazz = (*jenv)->GetObjectClass(jenv, myobject);
+	clazz = (*jenv)->GetObjectClass(jenv, myobject);
 	disconnect_mid = get_method_id("callbackDisconnect", "(I)V", jenv, clazz);
 	lock_mid = get_method_id("lockFunction", "(I)V", jenv, clazz);
 	unlock_mid = get_method_id("unlockFunction", "(I)V", jenv, clazz);
@@ -71,13 +72,14 @@
 
 JNIEXPORT void JNICALL Java_org_xmms2_SpecialJNI_setupMainloop(JNIEnv *jenv, jclass cls, jobject myobject, jlong jarg1){
 	xmmsc_connection_t *conn_ptr = (xmmsc_connection_t *) 0;
+	jclass clazz;
 	conn_ptr = *(xmmsc_connection_t **)(void *)&jarg1;
 	globalMainloopObj = (*jenv)->NewGlobalRef(jenv, myobject);
 	
 	if (jvm == NULL)
 		(*jenv)->GetJavaVM(jenv,&jvm);
 
-	jclass clazz = (*jenv)->GetObjectClass(jenv, myobject);
+	clazz = (*jenv)->GetObjectClass(jenv, myobject);
 	io_want_out_mid = get_method_id("callbackIOWantOut", "(II)V", jenv, clazz);
 	
 	//xmmsc_io_need_out_callback_set(conn_ptr, io_want_out_callback, 0);
