--- flow/ThreadPrimitives.cpp.orig	2019-01-09 22:28:32 UTC
+++ flow/ThreadPrimitives.cpp
@@ -37,7 +37,7 @@ extern std::string format( const char *form, ... );
 Event::Event() {
 #ifdef _WIN32
 	ev = CreateEvent(NULL, FALSE, FALSE, NULL);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	int result = sem_init(&sem, 0, 0);
 	if (result)
 		criticalError(FDB_EXIT_INIT_SEMAPHORE, "UnableToInitializeSemaphore", format("Could not initialize semaphore - %s", strerror(errno)).c_str());
@@ -54,7 +54,7 @@ Event::Event() {
 Event::~Event() {
 #ifdef _WIN32
 	CloseHandle(ev);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	sem_destroy(&sem);
 #elif defined(__APPLE__)
 	semaphore_destroy(self, sem);
@@ -66,7 +66,7 @@ Event::~Event() {
 void Event::set() {
 #ifdef _WIN32
 	SetEvent(ev);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	sem_post(&sem);
 #elif defined(__APPLE__)
 	semaphore_signal(sem);
@@ -78,7 +78,7 @@ void Event::set() {
 void Event::block() {
 #ifdef _WIN32
 	WaitForSingleObject(ev, INFINITE);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	int ret;
 	do {
 		ret = sem_wait(&sem);
