--- src/thread_signal.cpp.orig	2024-10-02 04:26:07 UTC
+++ src/thread_signal.cpp
@@ -120,7 +120,9 @@ namespace libthreadar
 		    if(sigemptyset(& sigac.sa_mask) != 0)
 			throw exception_system("Error calling sigemptyset(): ", errno);
 		    sigac.sa_flags = 0;
+#ifdef __linux__
 		    sigac.sa_restorer = nullptr;
+#endif
 
 		    if(sigaction(awaking_signal, &sigac, nullptr) != 0)
 			throw exception_system("Error calling sigaction(): ", errno);
