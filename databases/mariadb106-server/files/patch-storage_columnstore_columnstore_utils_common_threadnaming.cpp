--- storage/columnstore/columnstore/utils/common/threadnaming.cpp.orig	2021-08-04 18:07:21 UTC
+++ storage/columnstore/columnstore/utils/common/threadnaming.cpp
@@ -22,13 +22,21 @@ namespace utils
 {
     void setThreadName(const char *threadName)
     {
+#ifdef __FreeBSD__
+        pthread_set_name_np(pthread_self(), threadName);
+#else
         prctl(PR_SET_NAME, threadName, 0, 0, 0);
+#endif
     }
 
     std::string getThreadName()
     {
       char buf[32];
+#ifdef __FreeBSD__
+      pthread_get_name_np(pthread_self(), buf, sizeof(buf));
+#else
       prctl(PR_GET_NAME, buf, 0, 0, 0);
+#endif
       return std::string(buf);
     }
 } // end of namespace
