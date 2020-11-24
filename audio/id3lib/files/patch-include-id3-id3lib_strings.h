--- include/id3/id3lib_strings.h.orig	2003-03-02 00:23:00 UTC
+++ include/id3/id3lib_strings.h
@@ -30,6 +30,7 @@
 #define _ID3LIB_STRINGS_H_
 
 #include <string>
+#include <cstring>
 
 #if (defined(__GNUC__) && (__GNUC__ >= 3) || (defined(_MSC_VER) && _MSC_VER > 1000))
 namespace std
