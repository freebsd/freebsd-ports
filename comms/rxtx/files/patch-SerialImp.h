--- src/SerialImp.h.orig	2005-07-05 10:47:21.000000000 -0700
+++ src/SerialImp.h	2010-12-05 21:47:42.000000000 -0800
@@ -438,8 +438,13 @@
 void system_does_not_unlock( const char *, int );
 int check_group_uucp();
 int check_lock_pid( const char *, int );
 int printj(JNIEnv *env, wchar_t *fmt, ...);
 
+// BBB added
+void deref_java_object( JNIEnv *env, jobject jobj );
+void * get_java_varP( JNIEnv *env, jobject jobj, char *id, char *type );
+
+
 #define UNEXPECTED_LOCK_FILE "RXTX Error:  Unexpected lock file: %s\n Please report to the RXTX developers\n"
 #define LINUX_KERNEL_VERSION_ERROR "\n\n\nRXTX WARNING:  This library was compiled to run with OS release %s and you are currently running OS release %s.  In some cases this can be a problem.  Try recompiling RXTX if you notice strange behavior.  If you just compiled RXTX make sure /usr/include/linux is a symbolic link to the include files that came with the kernel source and not an older copy.\n\n\npress enter to continue\n"
 #define UUCP_ERROR "\n\n\nRXTX WARNING:  This library requires the user running applications to be in\ngroup uucp.  Please consult the INSTALL documentation.  More information is\navaiable under the topic 'How can I use Lock Files with rxtx?'\n" 
