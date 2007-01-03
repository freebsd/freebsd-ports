--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom.cpp.orig	Thu Sep 21 10:57:23 2006
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom.cpp	Wed Nov 29 19:46:27 2006
@@ -85,14 +85,16 @@
 }
 #endif
 
-#ifndef NO_NS_1InitEmbedding
-JNIEXPORT jint JNICALL XPCOM_NATIVE(NS_1InitEmbedding)
-	(JNIEnv *env, jclass that, jint arg0, jint arg1)
+#ifndef NO_NS_1InitXPCOM3
+JNIEXPORT jint JNICALL XPCOM_NATIVE(NS_1InitXPCOM3)
+	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
 {
 	jint rc = 0;
-	XPCOM_NATIVE_ENTER(env, that, NS_1InitEmbedding_FUNC);
-	rc = (jint)NS_InitEmbedding((nsILocalFile *)arg0, (nsIDirectoryServiceProvider *)arg1);
-	XPCOM_NATIVE_EXIT(env, that, NS_1InitEmbedding_FUNC);
+	XPCOM_NATIVE_ENTER(env, that, NS_1GetComponentRegistrar_FUNC);
+	rc = (jint)NS_InitXPCOM3((nsIServiceManager **)arg0, (nsIFile *)arg1,
+		(nsIDirectoryServiceProvider *)arg2, (nsStaticModuleInfo *)arg3,
+		(PRUint32) arg4);
+	XPCOM_NATIVE_EXIT(env, that, NS_1GetComponentRegistrar_FUNC);
 	return rc;
 }
 #endif
@@ -113,18 +115,6 @@
 }
 #endif
 
-#ifndef NO_NS_1TermEmbedding
-JNIEXPORT jint JNICALL XPCOM_NATIVE(NS_1TermEmbedding)
-	(JNIEnv *env, jclass that)
-{
-	jint rc = 0;
-	XPCOM_NATIVE_ENTER(env, that, NS_1TermEmbedding_FUNC);
-	rc = (jint)NS_TermEmbedding();
-	XPCOM_NATIVE_EXIT(env, that, NS_1TermEmbedding_FUNC);
-	return rc;
-}
-#endif
-
 #ifndef NO_PR_1Free
 JNIEXPORT void JNICALL XPCOM_NATIVE(PR_1Free)
 	(JNIEnv *env, jclass that, jint arg0)
@@ -141,7 +131,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, PR_1Malloc_FUNC);
-	rc = (jint)PR_Malloc(arg0);
+	rc = (long)PR_Malloc(arg0);
 	XPCOM_NATIVE_EXIT(env, that, PR_1Malloc_FUNC);
 	return rc;
 }
@@ -2091,7 +2081,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedCString_1get_FUNC);
-	rc = (jint)((nsEmbedCString *)arg0)->get();
+	rc = (long)((nsEmbedCString *)arg0)->get();
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedCString_1get_FUNC);
 	return rc;
 }
@@ -2103,7 +2093,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedCString_1new___FUNC);
-	rc = (jint)new nsEmbedCString();
+	rc = (long)new nsEmbedCString();
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedCString_1new___FUNC);
 	return rc;
 }
@@ -2117,7 +2107,7 @@
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedCString_1new___3BI_FUNC);
 	if (arg0) if ((lparg0 = env->GetByteArrayElements(arg0, NULL)) == NULL) goto fail;
-	rc = (jint)new nsEmbedCString((const char *)lparg0, arg1);
+	rc = (long)new nsEmbedCString((const char *)lparg0, arg1);
 fail:
 	if (arg0 && lparg0) env->ReleaseByteArrayElements(arg0, lparg0, 0);
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedCString_1new___3BI_FUNC);
@@ -2131,7 +2121,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedString_1Length_FUNC);
-	rc = (jint)((nsEmbedString *)arg0)->Length();
+	rc = (long)((nsEmbedString *)arg0)->Length();
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedString_1Length_FUNC);
 	return rc;
 }
@@ -2153,7 +2143,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedString_1get_FUNC);
-	rc = (jint)((nsEmbedString *)arg0)->get();
+	rc = (long)((nsEmbedString *)arg0)->get();
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedString_1get_FUNC);
 	return rc;
 }
@@ -2165,7 +2155,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedString_1new___FUNC);
-	rc = (jint)new nsEmbedString();
+	rc = (long)new nsEmbedString();
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedString_1new___FUNC);
 	return rc;
 }
@@ -2179,7 +2169,7 @@
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsEmbedString_1new___3C_FUNC);
 	if (arg0) if ((lparg0 = env->GetCharArrayElements(arg0, NULL)) == NULL) goto fail;
-	rc = (jint)new nsEmbedString(lparg0);
+	rc = (long)new nsEmbedString(lparg0);
 fail:
 	if (arg0 && lparg0) env->ReleaseCharArrayElements(arg0, lparg0, 0);
 	XPCOM_NATIVE_EXIT(env, that, nsEmbedString_1new___3C_FUNC);
@@ -2193,7 +2183,7 @@
 {
 	jboolean rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsID_1Equals_FUNC);
-	rc = (jboolean)((nsID *)arg0)->Equals(*(nsID *)arg1);
+	rc = (long)((nsID *)arg0)->Equals(*(nsID *)arg1);
 	XPCOM_NATIVE_EXIT(env, that, nsID_1Equals_FUNC);
 	return rc;
 }
@@ -2207,7 +2197,7 @@
 	jboolean rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsID_1Parse_FUNC);
 	if (arg1) if ((lparg1 = env->GetStringUTFChars(arg1, NULL)) == NULL) goto fail;
-	rc = (jboolean)((nsID *)arg0)->Parse((const char *)lparg1);
+	rc = (long)((nsID *)arg0)->Parse((const char *)lparg1);
 fail:
 	if (arg1 && lparg1) env->ReleaseStringUTFChars(arg1, lparg1);
 	XPCOM_NATIVE_EXIT(env, that, nsID_1Parse_FUNC);
@@ -2231,7 +2221,7 @@
 {
 	jint rc = 0;
 	XPCOM_NATIVE_ENTER(env, that, nsID_1new_FUNC);
-	rc = (jint)new nsID();
+	rc = (long)new nsID();
 	XPCOM_NATIVE_EXIT(env, that, nsID_1new_FUNC);
 	return rc;
 }
