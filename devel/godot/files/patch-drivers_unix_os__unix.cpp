--- drivers/unix/os_unix.cpp.orig	2014-12-15 18:49:18 UTC
+++ drivers/unix/os_unix.cpp
@@ -44,7 +44,9 @@
 #include "stream_peer_tcp_posix.h"
 #include "packet_peer_udp_posix.h"
 
-
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <stdarg.h>
 #include <sys/time.h>
 #include <sys/wait.h>
@@ -305,7 +307,17 @@ Error OS_Unix::execute(const String& p_p
 			args.push_back((char*)cs[i].get_data());// shitty C cast
 		args.push_back(0);
 
+#ifdef __FreeBSD__
+        if(p_path.find("/")) {
+            // exec name contains path so use it
+            execv(p_path.utf8().get_data(),&args[0]);
+        }else{
+            // use program name and search through PATH to find it
+		    execvp(getprogname(),&args[0]);
+		}
+#else
 		execv(p_path.utf8().get_data(),&args[0]);
+#endif
 		// still alive? something failed..
 		fprintf(stderr,"**ERROR** OS_Unix::execute - Could not create child process while executing: %s\n",p_path.utf8().get_data());
 		abort();
@@ -415,6 +427,12 @@ String OS_Unix::get_executable_path() co
 		return OS::get_executable_path();
 	}
 	return b;
+#elif defined(__FreeBSD__)
+    char resolved_path[MAXPATHLEN];
+    
+    realpath(OS::get_executable_path().utf8().get_data(), resolved_path);
+
+    return String(resolved_path);
 #else
 	ERR_PRINT("Warning, don't know how to obtain executable path on this OS! Please override this function properly.");
 	return OS::get_executable_path();
