--- TaskJugglerUI/TjGanttChart.cpp.orig	Sun Apr 30 01:56:22 2006
+++ TaskJugglerUI/TjGanttChart.cpp	Sun Apr 30 02:01:40 2006
@@ -994,7 +994,7 @@
         {
             const Task* t = static_cast<const Task*>
                 ((*it)->getCoreAttributes());
-            drawTask(t, false);
+            drawTask(t, (const Resource*)false);
 
             drawDependencies(t, collisionDetector);
         }
