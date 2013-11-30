--- exception/errnodescr.cc.orig	2013-10-02 12:36:00.000000000 +0200
+++ exception/errnodescr.cc	2013-11-27 15:02:26.000000000 +0100
@@ -7,16 +7,12 @@
 {
     if (errno != 0)
     {
-        char *buffer = new char[Exception::STRERROR_BUFSIZE];
-
-        if (char *cp = strerror_r(errno, buffer, Exception::STRERROR_BUFSIZE))
+        if (char *cp = strerror(errno))
             out << cp;
         else
         {
             out << "internal error: strerror_r failed with errno = " << errno;
         }
-
-        delete[] buffer;
     }
 
     return out;
