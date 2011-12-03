--- include/vki/vki-x86-freebsd.h.orig	2011-04-27 02:47:18.000000000 -0500
+++ include/vki/vki-x86-freebsd.h	2011-05-08 05:39:46.293802771 -0500
@@ -145,7 +145,7 @@ struct vki_sigcontext {
 	int	fpformat;
 	int	ownedfp;
 	int	spare1[1];
-	struct _vki_fpstate fpstate __aligned(16);
+	struct _vki_fpstate fpstate __attribute__((__aligned__(16)));
 	int	fsbase;
 	int	gsbase;
 	int	spare2[6];
@@ -215,7 +215,7 @@ struct vki_mcontext {
 	int	fpformat;
 	int	ownedfp;
 	int	spare1[1];
-	struct _vki_fpstate fpstate __aligned(16);
+	struct _vki_fpstate fpstate __attribute__((__aligned__(16)));
 	int	fsbase;
 	int	gsbase;
 	int	spare2[6];
