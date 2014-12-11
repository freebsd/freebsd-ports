--- ./plugins/collab/core/sync/xp/SynchronizedQueue.h.orig	2014-12-05 21:45:41.710482488 +0100
+++ ./plugins/collab/core/sync/xp/SynchronizedQueue.h	2014-12-05 21:46:02.610480585 +0100
@@ -28,7 +28,7 @@
 class EmptyQueueException {};
 
 template <typename T>
-class SynchronizedQueue : public Synchronizer, public boost::noncopyable
+class SynchronizedQueue : public Synchronizer, public asio::noncopyable
 {
 public:
 	SynchronizedQueue(boost::function<void (SynchronizedQueue&)> sig)
