--- exception/errnodescr.cc.orig	2013-10-01 16:50:34 UTC
+++ exception/errnodescr.cc
@@ -7,16 +7,12 @@ std::ostream &errnodescr(std::ostream &o
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
