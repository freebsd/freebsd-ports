--- src/SerialImp.c.orig	2006-01-29 14:19:04.000000000 -0800
+++ src/SerialImp.c	2010-12-05 22:41:39.000000000 -0800
@@ -1528,11 +1528,11 @@
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeDrain)( JNIEnv *env,
 	jobject jobj, jboolean interrupted )
 {
 	int fd = get_java_var( env, jobj,"fd","I" );
-	struct event_info_struct *eis = ( struct event_info_struct * ) get_java_var( env, jobj, "eis", "J" );
+	struct event_info_struct *eis = ( struct event_info_struct * ) get_java_varP( env, jobj, "eis", "J" ); // does not deref
 	int result, count=0;
 
 	char message[80];
 
 	ENTER( "SerialImp.c:drain()" );
@@ -1545,16 +1545,21 @@
 
 	sprintf( message, "RXTXPort:drain() returns: %i\n", result ); 
 	report_verbose( message );
 #if defined(__sun__)
 	/* FIXME: No time to test on all OS's for production */
+        deref_java_object(env, jobj);
 	return( JNI_TRUE );
 #endif /* __sun__ */
 	LEAVE( "RXTXPort:drain()" );
 	if( result ) throw_java_exception( env, IO_EXCEPTION, "nativeDrain",
 		strerror( errno ) );
-	if( interrupted ) return( JNI_FALSE );
+	if( interrupted )
+        {
+          deref_java_object(env, jobj);
+          return( JNI_FALSE );
+        }
 #if !defined(TIOCSERGETLSR) && !defined(WIN32)
 	if( eis && eis->writing )
 	{
 		eis->writing=JNI_FALSE;
 		eis->output_buffer_empty_flag = 0;
@@ -1565,10 +1570,12 @@
                 struct event_info_struct myeis =
 			build_threadsafe_eis( env, &jobj, eis );
 		send_event( &myeis, SPE_OUTPUT_BUFFER_EMPTY, 1 );
 	}
 	report_time_end( );
+
+        deref_java_object(env, jobj);
 	return( JNI_FALSE );
 }
 
 /*----------------------------------------------------------
 RXTXPort.sendBreak
@@ -2937,11 +2944,11 @@
 	struct timeval tv, *tvP;
 	fd_set rset;
 	/* TRENT */
 	int flag, count = 0;
 	struct event_info_struct *eis = ( struct event_info_struct * )
-		get_java_var( env, *jobj,"eis","J" );
+		get_java_varP( env, *jobj,"eis","J" ); // does not dereference object (pointer remains valid)
 	
 	report_time_start();
 	flag = eis->eventflags[SPE_DATA_AVAILABLE];
 	eis->eventflags[SPE_DATA_AVAILABLE] = 0;
 /*
@@ -2957,10 +2964,11 @@
 		if (timeout >= 0) {
 			now = GetTickCount();
 			if ( now-start >= timeout )
 			{
 				eis->eventflags[SPE_DATA_AVAILABLE] = flag;
+                                deref_java_object( env, *jobj );
 				return bytes;
 			}
 		}
 
 		FD_ZERO(&rset);
@@ -2983,22 +2991,25 @@
 #endif /* WIN32 */
 		if (ret == -1){
 			report( "read_byte_array: select returned -1\n" );
 			LEAVE( "read_byte_array" );
 			eis->eventflags[SPE_DATA_AVAILABLE] = flag;
+                        deref_java_object( env, *jobj );
 			return -1;
 		}
 		else if (ret > 0)
 		{
 			if ((ret = READ( fd, buffer + bytes, left )) < 0 ){
 				if (errno != EINTR && errno != EAGAIN){
 					report( "read_byte_array: read returned -1\n" );
 					LEAVE( "read_byte_array" );
 					eis->eventflags[SPE_DATA_AVAILABLE] = flag;
+                                        deref_java_object( env, *jobj );
 					return -1;
 				}
 				eis->eventflags[SPE_DATA_AVAILABLE] = flag;
+                                deref_java_object( env, *jobj );
 				return -1;
 			}
 			else if ( ret ) {
 				bytes += ret;
 				left -= ret;
@@ -3031,10 +3042,12 @@
 	report( msg );
 	LEAVE( "read_byte_array" );
 	report_time_end();
 */
 	eis->eventflags[SPE_DATA_AVAILABLE] = flag;
+
+        deref_java_object( env, *jobj );
 	return bytes;
 }
 
 #ifdef asdf
 int read_byte_array(	JNIEnv *env,
@@ -4898,10 +4911,43 @@
 	LEAVE( "get_java_var" );
 */
 	return result;
 }
 
+void deref_java_object( JNIEnv *env, jobject jobj )
+{
+  jclass jclazz = (*env)->GetObjectClass( env, jobj );
+  (*env)->DeleteLocalRef( env, jclazz );
+}
+
+void * get_java_varP( JNIEnv *env, jobject jobj, char *id, char *type )
+{
+	void * result = 0;
+	jclass jclazz = (*env)->GetObjectClass( env, jobj );
+	jfieldID jfd = (*env)->GetFieldID( env, jclazz, id, type );
+
+/*
+	ENTER( "get_java_var" );
+*/
+	if( !jfd ) {
+		(*env)->ExceptionDescribe( env );
+		(*env)->ExceptionClear( env );
+		(*env)->DeleteLocalRef( env, jclazz );
+		LEAVE( "get_java_var" );
+		return result;
+	}
+	result = (void *)( (*env)->GetObjectField( env, jobj, jfd ) );
+/* ct7 & gel * Added DeleteLocalRef */
+//	(*env)->DeleteLocalRef( env, jclazz );
+	if(!strncmp( "fd",id,2) && result == 0)
+		report_error( "get_java_var: invalid file descriptor\n" );
+/*
+	LEAVE( "get_java_var" );
+*/
+	return result;
+}
+
 /*----------------------------------------------------------
 throw_java_exception
 
    accept:      env (keyhole to java)
                 *exc (exception class name)
