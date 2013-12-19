--- src/im/auth_pam.cpp.orig
+++ src/im/auth_pam.cpp
@@ -19,6 +19,7 @@
 #include <cstring>
 #include <cerrno>
 #include <sys/types.h>
+#include <unistd.h>
 #include <pwd.h>
 
 #include "auth.h"
