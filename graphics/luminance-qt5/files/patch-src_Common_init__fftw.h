--- src/Common/init_fftw.h.orig	2021-01-11 09:41:28 UTC
+++ src/Common/init_fftw.h
@@ -22,7 +22,7 @@
 #ifndef INIT_FFTW_H
 #define INIT_FFTW_H
 
-#include <boost/thread/mutex.hpp>
+#include <mutex>
 
 class FFTW_MUTEX {
    public:
