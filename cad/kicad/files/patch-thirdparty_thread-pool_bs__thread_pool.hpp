commit 94e89463a3e708bd53cfc61287ef11d9917a9b7a
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    major/minor is known on FreeBSD, too

diff --git thirdparty/thread-pool/bs_thread_pool.hpp thirdparty/thread-pool/bs_thread_pool.hpp
index e9bb7ce2e0..d116d70c08 100644
--- thirdparty/thread-pool/bs_thread_pool.hpp
+++ thirdparty/thread-pool/bs_thread_pool.hpp
@@ -96,7 +96,7 @@ import std;
     #endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     // On Linux, <sys/sysmacros.h> defines macros called `major` and `minor`. We undefine them here so the `version` struct can work.
     #ifdef major
         #undef major
