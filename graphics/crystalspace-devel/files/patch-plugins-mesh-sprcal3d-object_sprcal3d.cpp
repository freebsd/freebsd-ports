--- plugins/mesh/sprcal3d/object/sprcal3d.cpp	Wed Aug 16 10:45:55 2006
+++ plugins/mesh/sprcal3d/object/sprcal3d.cpp	Wed Aug 16 23:34:50 2006
@@ -53,6 +53,8 @@
 
 
 #include "sprcal3d.h"
+#include <cal3d/coretrack.h>
+#include <cal3d/corekeyframe.h>
 
 // STL include required by cal3d
 #include <string>
@@ -657,10 +659,12 @@
     ->getVectorCoreBone();
 
   // loop through all root core bones
-  std::list<int>::iterator iteratorRootCoreBoneId;
-  for (iteratorRootCoreBoneId = pCoreSkeleton->getListRootCoreBoneId().begin()
-    ; iteratorRootCoreBoneId != pCoreSkeleton->getListRootCoreBoneId().end()
-    ; ++iteratorRootCoreBoneId)
+  std::vector<int>& rootCoreBones = 
+    pCoreSkeleton->getVectorRootCoreBoneId();
+  std::vector<int>::iterator iteratorRootCoreBoneId;
+  for (iteratorRootCoreBoneId = rootCoreBones.begin();
+       iteratorRootCoreBoneId != rootCoreBones.end();
+       ++iteratorRootCoreBoneId)
   {
     CalCoreBone *bone = vectorCoreBone[*iteratorRootCoreBoneId];
     CalQuaternion bonerot = bone->getRotation();
@@ -677,32 +681,25 @@
   {
     CalCoreAnimation *anim = calCoreModel.getCoreAnimation(i);
     if (!anim) continue;
-
-    const uint trackCount = anim->getTrackCount();
-    std::vector<CalTransform> poses = anim->getPoses();
-    const uint frameCount = (uint)poses.size() / trackCount;
-
     // loop through all root core bones
-    std::list<int>::iterator iteratorRootCoreBoneId;
-    for (iteratorRootCoreBoneId = pCoreSkeleton->getListRootCoreBoneId().begin()
-        ; iteratorRootCoreBoneId != pCoreSkeleton->getListRootCoreBoneId().end()
-    ; ++iteratorRootCoreBoneId)
+    for (iteratorRootCoreBoneId = rootCoreBones.begin();
+         iteratorRootCoreBoneId != rootCoreBones.end();
+         ++iteratorRootCoreBoneId)
     {
-      int boneTrack = anim->getTrackAssignment (*iteratorRootCoreBoneId);
-      if (boneTrack < 0) continue;
-      for (uint j = 0; j < frameCount; j++)
+      CalCoreTrack *track = anim->getCoreTrack(*iteratorRootCoreBoneId);
+      if (!track) continue;
+      for (int j=0; j<track->getCoreKeyframeCount(); j++)
       {
-        CalTransform& tf = poses[j * trackCount + boneTrack];
-        CalQuaternion bonerot = tf.getRotation();
-        CalVector bonevec = tf.getTranslation();
-        bonerot *= quatrot;
-        bonevec *= quatrot;
-        bonevec += translation;
-        tf.setRotation (bonerot);
-        tf.setTranslation (bonevec);
+	CalCoreKeyframe *frame = track->getCoreKeyframe(j);
+	CalQuaternion bonerot = frame->getRotation();
+	CalVector bonevec = frame->getTranslation();
+	bonerot *= quatrot;
+	bonevec *= quatrot;
+	bonevec += translation;
+	frame->setRotation(bonerot);
+	frame->setTranslation(bonevec);
       }
     }
-    anim->setPoses (poses, trackCount);
   }
 //  calCoreModel.getCoreSkeleton()->calculateBoundingBoxes(&calCoreModel);
 }
