--- extc/extc_stubs.c.orig	2007-03-05 14:09:37.000000000 +0300
+++ extc/extc_stubs.c	2009-04-11 12:57:23.000000000 +0400
@@ -32,6 +32,11 @@
 #	include <sys/syslimits.h>
 #	include <mach-o/dyld.h>
 #endif
+#ifdef __FreeBSD__
+#	include <sys/param.h>
+#	include <sys/sysctl.h>
+#	include <sys/user.h>
+#endif
 
 #define zval(z)		((z_streamp)(z))
 
@@ -125,7 +130,26 @@
 }
 
 CAMLprim value executable_path(value u) {
-#ifdef _WIN32
+#if defined(__FreeBSD__)
+	char pathname[PATH_MAX];
+	int error, name[4];
+	size_t len;
+	pid_t pid;
+
+	pid = getpid();
+	name[0] = CTL_KERN;
+	name[1] = KERN_PROC;
+	name[2] = KERN_PROC_PATHNAME;
+	name[3] = pid;
+	
+	len = sizeof(pathname);
+	error = sysctl(name, 4, pathname, &len, NULL, 0);
+	if (error < 0 && errno != ESRCH)
+		warn("sysctl: kern.proc.pathname: %d", pid);
+	if (error < 0)
+		return caml_copy_string("-");
+	return caml_copy_string(pathname);
+#elif defined(_WIN32)
 	char path[MAX_PATH];
 	if( GetModuleFileName(NULL,path,MAX_PATH) == 0 )
 		failwith("executable_path");
