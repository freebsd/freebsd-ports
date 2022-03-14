--- include/osmium/thread/util.hpp.orig	2022-02-07 12:59:17 UTC
+++ include/osmium/thread/util.hpp
@@ -38,8 +38,10 @@ DEALINGS IN THE SOFTWARE.
 #include <thread>
 #include <utility>
 
-#ifdef __linux__
+#if defined(__linux__)
 # include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+# include <pthread.h>
 #endif
 
 namespace osmium {
@@ -72,9 +74,13 @@ namespace osmium {
         /**
          * Set name of current thread for debugging. This only works on Linux.
          */
-#ifdef __linux__
+#if defined(__linux__)
         inline void set_thread_name(const char* name) noexcept {
             prctl(PR_SET_NAME, name, 0, 0, 0);
+        }
+#elif defined(__FreeBSD__)
+        inline void set_thread_name(const char* name) noexcept {
+			pthread_setname_np(pthread_self(), name);
         }
 #else
         inline void set_thread_name(const char*) noexcept {
