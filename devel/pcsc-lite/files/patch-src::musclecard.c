--- src/musclecard.c.dist  Sat Jul 13 03:43:40 2002
+++ src/musclecard.c       Sat Jul 13 03:43:59 2002
@@ -43,7 +43,9 @@
 
 static SCARDCONTEXT localHContext = 0;
 static ULONG blockingContext      = MSC_BLOCKSTATUS_RESUME;
+#ifdef USE_THREAD_SAFETY
 static PCSCLITE_THREAD_T callbackThread;
+#endif
 
 /*
  * internal function 
