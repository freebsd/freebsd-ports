--- libs/Common/CriticalSection.h.orig	2022-07-12 17:18:30 UTC
+++ libs/Common/CriticalSection.h
@@ -53,7 +53,7 @@ class CriticalSection   (protected)
 
 public:
 	CriticalSection() {
-		#ifdef __APPLE__
+		#if defined(__APPLE__) || defined(__FreeBSD__)
 		pthread_mutex_init(&mtx, NULL);
 		#else
 		mtx = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
@@ -62,7 +62,7 @@ class CriticalSection   (protected)
 	~CriticalSection() { pthread_mutex_destroy(&mtx); }
 	void Clear() {
 		pthread_mutex_destroy(&mtx);
-		#ifdef __APPLE__
+		#if defined(__APPLE__) || defined(__FreeBSD__)
 		pthread_mutex_init(&mtx, NULL);
 		#else
 		mtx = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
