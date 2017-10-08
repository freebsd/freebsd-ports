The #else part is ill-formed, and the multi-instance support can
work on FreeBSD as well as Linux.

--- src/Main.cpp.orig	2017-10-06 07:17:05 UTC
+++ src/Main.cpp
@@ -192,7 +192,7 @@ int main(int argc, char *argv[]) 
 		return 0;
 	}
 
-#ifdef Q_OS_LINUX
+#if defined( Q_OS_LINUX ) || defined( Q_OS_FREEBSD )
 
 	int pid=0;
 	if( !cmd_data.multiple_instances ){
@@ -203,9 +203,6 @@ int main(int argc, char *argv[]) 
 		notify_old_instance(cmd_data.files_to_play, pid);
 		return 0;
 	}
-
-#else
-	Q_UNUSED(single_instance)
 #endif
 
 
