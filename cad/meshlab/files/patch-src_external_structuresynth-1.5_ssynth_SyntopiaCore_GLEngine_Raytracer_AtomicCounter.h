--- src/external/structuresynth-1.5/ssynth/SyntopiaCore/GLEngine/Raytracer/AtomicCounter.h.orig	2020-07-27 23:02:57 UTC
+++ src/external/structuresynth-1.5/ssynth/SyntopiaCore/GLEngine/Raytracer/AtomicCounter.h
@@ -2,6 +2,7 @@
 
 #include <QMutex>
 #include <QWaitCondition>
+#include <climits>
 
 namespace SyntopiaCore {
 	namespace GLEngine {	
