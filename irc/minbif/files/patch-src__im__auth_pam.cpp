--- src/im/auth_pam.cpp.orig	2011-12-04 14:24:51 UTC
+++ src/im/auth_pam.cpp
@@ -19,6 +19,7 @@
 #include <cstring>
 #include <cerrno>
 #include <sys/types.h>
+#include <unistd.h>
 #include <pwd.h>
 
 #include "auth.h"
@@ -189,7 +190,7 @@ bool AuthPAM::setPassword(const string& password)
 	pam_conv_func_data.update = true;
 	pam_conv_func_data.new_password = password;
 
-	retval = pam_chauthtok(pamh, NULL);
+	retval = pam_chauthtok(pamh, 0);
 	if (retval != PAM_SUCCESS)
 		b_log[W_ERR] << "PAM: Password change failed: " << pam_strerror(pamh, retval);
 
