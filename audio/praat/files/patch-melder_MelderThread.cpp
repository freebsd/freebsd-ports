--- melder/MelderThread.cpp.orig	2026-06-09 16:04:19 UTC
+++ melder/MelderThread.cpp
@@ -103,7 +103,7 @@ integer MelderThread_computeNumberOfThreads (
 		#elif defined (_WIN32)
 			Melder_iroundDown ((double) numberOfElements / 2.0 / minimumNumberOfElementsPerThread);
 				// round down, assuming that the first spawned thread is the costliest
-		#elif defined (linux)
+		#elif defined (linux) || defined(UNIX)
 			Melder_iround ((double) numberOfElements / 1.5 / minimumNumberOfElementsPerThread);
 				// round to nearest, assuming that all spawned threads are equally costly
 		#else
