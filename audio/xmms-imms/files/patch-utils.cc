--- utils.cc.orig	Wed Aug 18 01:56:28 2004
+++ utils.cc	Tue Aug 31 15:44:15 2004
@@ -11,23 +11,6 @@
 using std::ofstream;
 using std::ios_base;
 
-// Random
-int imms_random(int max)
-{
-    int rand_num;
-    static struct random_data rand_data;
-    static char rand_state[256];
-    static bool initialized = false;
-    if (!initialized)
-    {
-        initstate_r(time(0), rand_state, sizeof(rand_state), &rand_data);
-        initialized = true;
-    }
-    random_r(&rand_data, &rand_num);
-    double cof = rand_num / (RAND_MAX + 1.0);
-    return (int)(max * cof);
-}
-
 time_t usec_diff(struct timeval &tv1, struct timeval &tv2)
 {
     return (tv2.tv_sec - tv1.tv_sec) * 1000000
