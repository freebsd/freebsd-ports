--- cjeca32/Debug.cpp.orig	2026-04-18 11:08:45 UTC
+++ cjeca32/Debug.cpp
@@ -165,7 +165,7 @@ CDebug Debug(0xffffffff);
 
 
 
-#elif defined(OS_LINUX) || defined(OS_DARWIN)
+#elif defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)
 
 #if defined(OS_DARWIN)
 # define DEBUG_DEFAULT_LOGFILE "/Library/Logs/cj.log"
