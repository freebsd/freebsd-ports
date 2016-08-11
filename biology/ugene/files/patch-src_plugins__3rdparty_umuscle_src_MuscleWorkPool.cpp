--- src/plugins_3rdparty/umuscle/src/MuscleWorkPool.cpp.orig	2016-03-31 12:22:09 UTC
+++ src/plugins_3rdparty/umuscle/src/MuscleWorkPool.cpp
@@ -28,9 +28,10 @@ namespace U2 {
 
     MuscleWorkPool::MuscleWorkPool(MuscleContext *_ctx, const MuscleTaskSettings  &_config, TaskStateInfo& _ti, int _nThreads, const MAlignment& _ma, MAlignment& _res, bool _mhack)
         :ctx(_ctx), config(_config), ma(_ma), res(_res), mhack(_mhack), Weights(NULL), ProgNodes(NULL), ph(NULL), ti(_ti),
-        treeNodeStatus(NULL), treeNodeIndexes(NULL), nThreads(_nThreads), uJoin(0), ptrbOscillating(false), bAnyAccepted(false), InternalNodeIndexes(NULL), uInternalNodeCount(0),
+        treeNodeStatus(NULL), treeNodeIndexes(NULL), nThreads(_nThreads), uJoin(0), bAnyAccepted(false), InternalNodeIndexes(NULL), uInternalNodeCount(0),
         bReversed(false), bRight(false), History(NULL), bLockLeft(NULL), bLockRight(false), msaIn(NULL)
     {
+            *ptrbOscillating = false;
             refineConstructot();
     }
     MuscleWorkPool::~MuscleWorkPool() {
