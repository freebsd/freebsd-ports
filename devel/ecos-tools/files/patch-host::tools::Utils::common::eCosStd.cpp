$FreeBSD$

Index: ../ecos/host/tools/Utils/common/eCosStd.cpp
===================================================================
RCS file: /home/tg/cvs/ecos/host/tools/Utils/common/eCosStd.cpp,v
retrieving revision 1.1.1.1
diff -u -r1.1.1.1 eCosStd.cpp
--- host/tools/Utils/common/eCosStd.cpp	22 Aug 2003 11:37:35 -0000	1.1.1.1
+++ host/tools/Utils/common/eCosStd.cpp	6 Sep 2003 17:23:26 -0000
@@ -33,10 +33,12 @@
   SystemTimeToFileTime(&st,(FILETIME *)&ft);
   return Time(ft)/10000;
 #else // UNIX
-  struct timeb tp;
-  ftime(&tp);
+  struct timeval tv;
+  struct timezone tz;
+  
+  gettimeofday(&tv, &tz);
   // A negative time would be bad news, but we're not in touble until 2038
-  return 1000*Time(tp.time)+tp.millitm;
+  return 1000*Time(tv.tv_sec)+tv.tv_usec/1000;
 #endif
 }
 
