--- network.cc.orig	Thu Nov 27 00:48:49 2003
+++ network.cc	Wed Feb 22 16:33:40 2006
@@ -554,6 +554,7 @@
   strcpy(HostName,"local pipe");
   sprintf(HostAddress,"pipe[%d,%d]",pin,pout);
   Quiet=0;
+  use_execve=0;
 }
 
 void PipeConnection::init() {
@@ -564,6 +565,7 @@
   strcpy(HostAddress,"unknown");
   memset(HelperBin,0,512);
   Quiet=0;
+  use_execve=0;
   handshake.erase();
 }
 
@@ -594,6 +596,25 @@
   Port=port;
   strncpy(HostName,host,128);
 
+  // Special handling for timeseal on FreeBSD:
+  //
+  // On FreeBSD, the games/timeseal port provides an a.out timeseal
+  // binary. However, a.out support is disabled by default on FreeBSD
+  // >= 5.x. If the a.out kernel module is not loaded, or if a.out
+  // support is not compiled into the kernel, execvp()ing timeseal
+  // will not return (because it fallbacks to the shell when execve()
+  // returns NOEXEC): eboard will not notice the failure (in
+  // PipeConnection::open()) and will therefore not fallback to a
+  // direct connection.
+  //
+  // We solve the problem by executing timeseal with execve(), which
+  // will fail if a.out support is not available. Note that unlike
+  // execvp(), execve() does not search for the program in the path,
+  // but this is not a problem since eboard uses the absolute path to
+  // timeseal.
+  if (! strcmp(helperbin, "timeseal"))
+    use_execve = 1;
+
   // build helper path
   if (helpersuffix)
     sprintf(z,"%s.%s",helperbin,helpersuffix);
@@ -702,7 +723,10 @@
     dup2(1,2);
 
     setpgid(getpid(),0); // to broadcast SIGKILL later
-    execvp(HelperBin,arguments);
+    if (use_execve)
+      execve(HelperBin,arguments,NULL);
+    else
+      execvp(HelperBin,arguments);
     write(1,"exec failed\n",12);
     global.debug("exec failed",HelperBin);
     _exit(2); // eek
