--- 7zip/Crypto/RarAES/sha1.cpp.orig	Sat Oct 30 01:04:01 2004
+++ 7zip/Crypto/RarAES/sha1.cpp	Fri Nov 19 09:41:13 2004
@@ -4,6 +4,7 @@
 #include "StdAfx.h"
 
 #include "sha1.h"
+#include <sys/endian.h>
 
 /*
 SHA-1 in C
