--- src/aolib/bfcryptfile.cpp.orig	Fri Mar 12 06:10:10 2004
+++ src/aolib/bfcryptfile.cpp	Sun Aug 20 09:12:01 2006
@@ -18,6 +18,7 @@
 
 
 #include <aolib/bfcryptfile.hpp>
+#include "openssl/sha.h"
 
 namespace aolib
 {
