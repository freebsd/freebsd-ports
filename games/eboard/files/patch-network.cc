--- network.cc.orig	2018-07-31 18:02:19 UTC
+++ network.cc
@@ -501,7 +501,7 @@ int IncomingConnection::createSocket() {
   sin.sin_addr.s_addr = INADDR_ANY;
   sin.sin_port = htons(Port);
     
-  if (bind(netsocket,(struct sockaddr *) &sin,sizeof(sin))==-1) {
+  if (::bind(netsocket,(struct sockaddr *) &sin,sizeof(sin))==-1) {
     snprintf(errorMessage,128,_("Unable to bind on port %d."),Port);
     return(-1);
   }
@@ -604,6 +604,7 @@ PipeConnection::PipeConnection(int _pin,int _pout) {
   strcpy(HostName,"local pipe");
   snprintf(HostAddress,96,"pipe[%d,%d]",pin,pout);
   Quiet=0;
+  use_execve=0;
   MaxWaitTime = 60000.0; // 1 minute
 }
 
@@ -615,6 +616,7 @@ void PipeConnection::init() {
   strcpy(HostAddress,"unknown");
   memset(HelperBin,0,512);
   Quiet=0;
+  use_execve=0;
   handshake.erase();
   MaxWaitTime = 60000.0; // 1 minute
 }
@@ -652,6 +654,25 @@ PipeConnection::PipeConnection(const char *host,int po
   Port=port;
   g_strlcpy(HostName,host,128);
 
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
     snprintf(z,256,"%s.%s",helperbin,helpersuffix);
@@ -768,7 +789,10 @@ int PipeConnection::open() {
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
