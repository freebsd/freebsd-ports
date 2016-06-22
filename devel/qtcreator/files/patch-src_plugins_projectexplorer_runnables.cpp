--- src/plugins/projectexplorer/runnables.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/projectexplorer/runnables.cpp
@@ -35,4 +35,6 @@ bool operator==(const StandardRunnable &
         && r1.environment == r2.environment;
 }
 
+void *StandardRunnable::staticTypeId = &StandardRunnable::staticTypeId;
+
 } // namespace ProjectExplorer
