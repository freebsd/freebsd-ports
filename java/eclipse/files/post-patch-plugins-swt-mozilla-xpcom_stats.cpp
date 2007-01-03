--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom_stats.cpp.orig	Wed Nov 29 12:03:05 2006
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom_stats.cpp	Wed Nov 29 12:05:26 2006
@@ -31,15 +31,14 @@
 
 #ifdef NATIVE_STATS
 
-int XPCOM_nativeFunctionCount = 132;
-int XPCOM_nativeFunctionCallCount[132];
+int XPCOM_nativeFunctionCount = 131;
+int XPCOM_nativeFunctionCallCount[131];
 char * XPCOM_nativeFunctionNames[] = {
 	"Call",
 	"NS_1GetComponentManager",
 	"NS_1GetServiceManager",
-	"NS_1InitEmbedding",
+	"NS_1InitXPCOM3_FUNC",
 	"NS_1NewLocalFile",
-	"NS_1TermEmbedding",
 	"PR_1Free",
 	"PR_1Malloc",
 	"VtblCall__II",
