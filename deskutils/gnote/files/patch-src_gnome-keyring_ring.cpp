--- src/gnome_keyring/ring.cpp.orig	2013-10-30 16:54:52.000000000 +0100
+++ src/gnome_keyring/ring.cpp	2013-10-30 16:56:09.000000000 +0100
@@ -20,6 +20,7 @@
 
 
 #include <cstring>
+#include <cstdlib>
 
 #include "keyringexception.hpp"
 #include "ring.hpp"
