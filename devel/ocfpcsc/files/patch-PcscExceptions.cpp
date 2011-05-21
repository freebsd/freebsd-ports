--- PcscExceptions.cpp.orig	2011-05-12 01:27:15.000000000 +0200
+++ PcscExceptions.cpp	2011-05-12 01:28:07.000000000 +0200
@@ -77,7 +77,7 @@
     /* allocate enough bufferspace for the complete exception message */
     completeMsg = (char *)malloc(strlen(method) + strlen(msg) + 50);
     sprintf(completeMsg, "PCSC Exception in method %s: %s\n" \
-	    "return code = %8.8x\n", method, msg,returnCode);
+	    "return code = %8.8lx\n", method, msg,returnCode);
 
     if ((exceptionMsg = env->NewStringUTF(completeMsg)) == NULL) {
 	free(completeMsg);
