--- utils.h.orig	Wed Aug 18 01:56:28 2004
+++ utils.h	Tue Aug 31 21:40:20 2004
@@ -1,7 +1,9 @@
 #ifndef __UTILS_H
 #define __UTILS_H
 
+#include <fcntl.h>
 #include <sys/time.h>
+#include <stdexcept>
 #include <string>
 
 #define     HOUR                    (60*60)
@@ -10,8 +12,32 @@
 
 using std::string;
 
-int imms_random(int max);
 time_t usec_diff(struct timeval &tv1, struct timeval &tv2);
+
+class ImmsRandom
+{
+public:
+    ImmsRandom()
+    {
+	urandom = open("/dev/urandom", O_RDONLY);
+	if (urandom == -1)
+	    throw std::runtime_error("could not open /dev/urandom");
+    }
+    ~ImmsRandom()
+    {
+	(void)close(urandom);
+    }
+    int imms_random(int max)
+    {
+	unsigned long rand_num;
+
+        (void)read(urandom, &rand_num, sizeof(rand_num));
+        double cof = rand_num / (ULONG_MAX + 1.0);
+        return (int)(max * cof);
+    }
+private:
+    int urandom;
+};
 
 class StackTimer
 {
