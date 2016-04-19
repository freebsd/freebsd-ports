--- iodev/network/slirp/compat.cc.orig	2015-05-01 19:41:08 UTC
+++ iodev/network/slirp/compat.cc
@@ -128,6 +128,8 @@ int qemu_socket(int domain, int type, in
 #define CONFIG_SMBD_COMMAND "/usr/sbin/smbd"
 
 #include <pwd.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 
 /* automatic user mode samba server configuration */
 void slirp_smb_cleanup(Slirp *s, char *smb_tmpdir)
