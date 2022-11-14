--- cjeca32/Debug.cpp.orig	2021-11-03 13:00:16 UTC
+++ cjeca32/Debug.cpp
@@ -141,7 +141,7 @@ CDebug Debug(0xffffffff);



-#elif defined(OS_LINUX) || defined(OS_DARWIN)
+#elif defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)

 #if defined(OS_DARWIN)
 # define DEBUG_DEFAULT_LOGFILE "/Library/Logs/cj.log"
