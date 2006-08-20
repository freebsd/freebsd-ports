--- linux/sys_linux.c	Sat Aug 19 21:04:32 2006
+++ linux/sys_linux.c	Sat Aug 19 21:04:55 2006
@@ -380,7 +380,7 @@
 
 #if defined __FreeBSD__
 #if defined __i386__
-#define ARCH "freebsd_i386"
+#define ARCH "i386"
 
 #ifdef NDEBUG
 	const char *debugdir = "freebsd_releasei386";
@@ -389,7 +389,7 @@
 #endif
 
 #elif defined __x86_64__
-#define ARCH "xfreebsd_86_64"
+#define ARCH "x86_64"
 #ifdef NDEBUG
 	const char *debugdir = "releasex86_64";
 #else
