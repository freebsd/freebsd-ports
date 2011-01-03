--- src/SerialImp.cpp.orig	2004-10-12 01:59:27.000000000 -0700
+++ src/SerialImp.cpp	2010-12-06 21:48:20.000000000 -0800
@@ -1736,10 +1736,50 @@
 		report("invalid file descriptor\n");
 #endif
 	return result;
 }
 
+void deref_java_object( JNIEnv *env, jobject jobj )
+{
+  jclass jclazz = env->GetObjectClass( env, jobj );
+  env->DeleteLocalRef( env, jclazz );
+}
+
+void * get_java_varP( JNIEnv *env, jobject jobj, char *id, char *type )
+{
+
+
+   ////////////////// Open Log File /////////////////////
+   fp = fopen("RXTXOut.log", "a");
+   fprintf(fp, "Brian is inside get_java_varP\n"); // !!!
+   fclose(fp);
+   ////////////////// Close Log File ////////////////////
+
+	void * result = 0;
+	//jclass jclazz = (*env)->GetObjectClass( env, jobj );
+	jclass jclazz = env->GetObjectClass( jobj ); // !!!
+	//jfieldID jfd = (*env)->GetFieldID( env, jclazz, id, type );
+    jfieldID jfd = env->GetFieldID( jclazz, id, type ); // !!!
+    
+	if( !jfd ) {
+		//(*env)->ExceptionDescribe( env );
+		env->ExceptionDescribe(); // !!!
+		//(*env)->ExceptionClear( env );
+		env->ExceptionClear(); // !!!
+		return result;
+	}
+	//result = (int)( (*env)->GetIntField( env, jobj, jfd ) );
+	result = (void *)( env->GetIntField( jobj, jfd ) ); // !!!
+/* ct7 & gel * Added DeleteLocalRef */
+	//(*env)->DeleteLocalRef( env, jclazz );
+//	env->DeleteLocalRef( jclazz ); // !!!
+#ifdef DEBUG
+	if(!strncmp("fd",id,2) && result == 0)
+		report("invalid file descriptor\n");
+#endif
+	return result;
+}
 /*----------------------------------------------------------
 throw_java_exception
 
    accept:      env (keyhole to java)
                 *exc (exception class name)
