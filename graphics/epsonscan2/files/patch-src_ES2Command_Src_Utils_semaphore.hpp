--- src/ES2Command/Src/Utils/semaphore.hpp.orig	2021-11-25 00:56:55 UTC
+++ src/ES2Command/Src/Utils/semaphore.hpp
@@ -23,6 +23,10 @@
        
 #include<sys/sem.h>
 #include <stdexcept>
+#ifdef __FreeBSD__
+#include <chrono>
+#include <thread>
+#endif
 #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
 #else
     union semun {
@@ -88,9 +92,26 @@ class semaphore (public)
     }
     int wait(int timeout_s)
     {
+#ifdef __FreeBSD__
+	int err;
         sembuf operations[1];
         operations[0].sem_num = 0;
         operations[0].sem_op = WAIT;
+        operations[0].sem_flg = SEM_UNDO | IPC_NOWAIT;
+	for (int i = 0; i < timeout_s * 100; i++) {
+		err = semop(sem_id_, operations, 1);
+		if (err == EAGAIN) {
+			std::this_thread::sleep_for(std::chrono::milliseconds(10));
+		}
+		else {
+			return err;
+		}
+	}
+	return ETIMEDOUT;
+#else
+        sembuf operations[1];
+        operations[0].sem_num = 0;
+        operations[0].sem_op = WAIT;
         operations[0].sem_flg = SEM_UNDO;
         struct timespec time{};
         time.tv_sec = timeout_s;
@@ -98,6 +119,7 @@ class semaphore (public)
             return errno;
         }
         return 0;
+#endif
     }
     void lock()
     {
@@ -128,6 +150,14 @@ class semaphore (public)
     }
     int wait_and_lock(int timeout_s)
     {
+#ifdef __FreeBSD__
+	int err;
+	if ((err = wait(timeout_s)) == 0) {
+		lock();
+		return 0;
+	}
+	return err;
+#else
         sembuf operations[2];
         operations[0].sem_num = 0;
         operations[0].sem_op = WAIT;
@@ -141,6 +171,7 @@ class semaphore (public)
             return errno;
         }
         return 0;
+#endif
     }
 private:
     key_t key_;
