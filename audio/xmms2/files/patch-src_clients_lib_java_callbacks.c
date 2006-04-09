--- src/clients/lib/java/callbacks.c.orig	Mon Mar 27 11:34:45 2006
+++ src/clients/lib/java/callbacks.c	Sat Apr  8 00:27:56 2006
@@ -38,11 +38,12 @@
 }
 
 void io_want_out_callback(int val, void *error){
+	jobject callbackObject;
 	JNIEnv *environment = checkEnv();  
 	if (environment == NULL)
 		return;
 	
-	jobject callbackObject = (*environment)->NewLocalRef(environment, globalMainloopObj);
+	callbackObject = (*environment)->NewLocalRef(environment, globalMainloopObj);
 	if (io_want_out_mid == 0)
 		return;
 
@@ -117,6 +118,7 @@
 void callback_dict_foreach_function(const void *key, xmmsc_result_value_type_t type, const void *value, void *user_data){
 	jint jres_val = 0;
 	jstring jkey, jvalue;
+	jobject callbackObject;
 	JNIEnv *environment = checkEnv();
 	
 	if (key == NULL || value == NULL) return;
@@ -124,7 +126,7 @@
 	if (environment == NULL)
 		return;
 	
-	jobject callbackObject = (*environment)->NewLocalRef(environment, globalObj);
+	callbackObject = (*environment)->NewLocalRef(environment, globalObj);
 	if (dict_foreach_mid == 0)
 	        return;
 	
@@ -138,13 +140,14 @@
 void callback_propdict_foreach_function(const void *key, xmmsc_result_value_type_t type, const void *value, const char *source, void *user_data){
 	jint jres_val = 0;
 	jstring jkey, jvalue, jsource;
+	jobject callbackObject;
 	JNIEnv *environment = checkEnv();
 	if (environment == NULL)
 		return;
 		
 	if (key == NULL || value == NULL) return;
 	
-	jobject callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
+	callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
 	if (propdict_foreach_mid == 0)
 	        return;
 	
@@ -173,12 +176,13 @@
 
 void run_java_callback_result_void(xmmsc_result_t *res, jmethodID mid, void *user_data){
 	jlong jresult = 0;
+	jobject callbackObject;
 	JNIEnv *environment = checkEnv();
     
 	if (environment == NULL)
 		return;
 		
-	jobject callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
+	callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
 	if (mid == 0)
 	        return;
    
@@ -188,10 +192,11 @@
 
 void run_java_callback_void(void *v, jmethodID mid){
 	JNIEnv *environment = checkEnv();
+	jobject callbackObject;
 	if (environment == NULL)
 		return;
 	
-	jobject callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
+	callbackObject = (*environment)->NewLocalRef(environment, globalObj);   
 	if (mid == 0)
         	return;
 
