--- iodev/network/slirp/compat.cc.orig
+++ iodev/network/slirp/compat.cc
@@ -127,6 +127,8 @@
 #define CONFIG_SMBD_COMMAND "/usr/sbin/smbd"
 
 #include <pwd.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 
 /* automatic user mode samba server configuration */
 void slirp_smb_cleanup(Slirp *s, char *smb_tmpdir)
