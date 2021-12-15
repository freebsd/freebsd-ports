--- src/util/virprocess.c.orig	2021-12-14 12:38:57 UTC
+++ src/util/virprocess.c
@@ -480,7 +480,7 @@ int virProcessKillPainfully(pid_t pid, bool force)
     return virProcessKillPainfullyDelay(pid, force, 0, false);
 }
 
-#if WITH_DECL_CPU_SET_T
+#if WITH_DECL_CPU_SET_T && defined(__linux__)
 
 int virProcessSetAffinity(pid_t pid, virBitmap *map, bool quiet)
 {
