--- cpucycles/wrapper.c.orig	2024-10-29 18:59:34 UTC
+++ cpucycles/wrapper.c
@@ -26,7 +26,7 @@ void cpucycles_tracesetup(void)
   tracesetup = 1;
 }
 
-static jmp_buf crash_jmp;
+static sigjmp_buf crash_jmp;
 
 static void crash(int s)
 {
