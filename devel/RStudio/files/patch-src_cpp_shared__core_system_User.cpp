- Workaround for https://github.com/rstudio/rstudio/issues/8908

--- src/cpp/shared_core/system/User.cpp.orig	2021-02-05 21:40:04 UTC
+++ src/cpp/shared_core/system/User.cpp
@@ -64,6 +64,8 @@ struct User::Impl
 
       // Get the maximum size of a passwd for this system.
       long buffSize = ::sysconf(_SC_GETPW_R_SIZE_MAX);
+      if (buffSize == -1)
+      	buffSize = 4096;
       if (buffSize == 1)
          buffSize = 4096; // some systems return -1, be conservative!
 
