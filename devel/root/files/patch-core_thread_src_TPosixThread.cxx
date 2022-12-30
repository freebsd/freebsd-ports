--- core/thread/src/TPosixThread.cxx.orig	2022-11-16 10:35:46 UTC
+++ core/thread/src/TPosixThread.cxx
@@ -37,7 +37,7 @@ Int_t TPosixThread::Run(TThread *th, const int affinit
    pthread_attr_init(attr);
    
    if (affinity >= 0) {
-   #ifdef R__MACOSX
+   #if defined(R__MACOSX) || defined(R__FBSD)
       Warning("Run", "Affinity setting not yet implemented on MacOS");
    #else
       cpu_set_t cpuset;
