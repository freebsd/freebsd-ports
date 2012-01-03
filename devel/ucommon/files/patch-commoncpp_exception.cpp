--- commoncpp/exception.cpp.orig	2012-01-03 10:17:46.000000000 +0100
+++ commoncpp/exception.cpp	2012-01-03 10:19:18.000000000 +0100
@@ -89,7 +89,7 @@
     if ( !_systemErrorString )
         _systemErrorString = new char[errStrSize];
 #ifndef _MSWINDOWS_
-#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
+#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && defined(_GNU_SOURCE)
     strerror_r(_systemError, _systemErrorString, errStrSize);
     return _systemErrorString;
 #else
