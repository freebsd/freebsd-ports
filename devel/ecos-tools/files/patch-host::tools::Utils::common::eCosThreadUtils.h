$FreeBSD$

Index: ../ecos/host/tools/Utils/common/eCosThreadUtils.h
===================================================================
RCS file: /home/tg/cvs/ecos/host/tools/Utils/common/eCosThreadUtils.h,v
retrieving revision 1.1.1.1
diff -u -r1.1.1.1 eCosThreadUtils.h
--- host/tools/Utils/common/eCosThreadUtils.h	22 Aug 2003 11:37:35 -0000	1.1.1.1
+++ host/tools/Utils/common/eCosThreadUtils.h	6 Sep 2003 16:37:19 -0000
@@ -61,7 +61,7 @@
 #ifdef _WIN32
   typedef DWORD THREAD_ID;
 #else // UNIX
-  #ifndef NO_THREADS
+  #ifdef NO_THREADS
     typedef int THREAD_ID;
   #else
     typedef pthread_t THREAD_ID;
