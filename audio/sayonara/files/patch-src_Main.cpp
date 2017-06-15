--- src/Main.cpp.orig	2016-10-30 11:53:25 UTC
+++ src/Main.cpp
@@ -38,7 +38,7 @@
 #include <QtGlobal>
 #include <algorithm>
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	#include <execinfo.h>		// backtrace
 	#include <csignal>			// kill/signal
 	#include <sys/types.h>		// kill
@@ -150,7 +150,7 @@ void segfault_handler(int sig){
 
 	Q_UNUSED(sig)
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 
 	void* array[10];
 	size_t size;
@@ -176,7 +176,7 @@ int main(int argc, char *argv[]) {
 #endif
 
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 
 	signal(SIGSEGV, segfault_handler);
 
@@ -187,7 +187,7 @@ int main(int argc, char *argv[]) {
 		return 0;
 	}
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 
 	int pid=0;
 	if( !cmd_data.multiple_instances ){
