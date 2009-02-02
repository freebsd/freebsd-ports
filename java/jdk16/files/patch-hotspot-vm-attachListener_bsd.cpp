$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/attachListener_bsd.cpp	28 Mar 2007 04:52:28 -0000	1.1
+++ ../../hotspot/src/os/bsd/vm/attachListener_bsd.cpp	2 Feb 2009 00:30:06 -0000
@@ -163,24 +163,11 @@
   struct sockaddr_un addr;
   addr.sun_family = AF_UNIX;
 
-  // FIXME: Prior to b39 the tool-side API expected to find the well
-  // known file in the working directory. To allow this libjvm.so work with
-  // a pre-b39 SDK we create it in the working directory if
-  // +StartAttachListener is used is used. All unit tests for this feature
-  // currently used this flag. Once b39 SDK has been promoted we can remove
-  // this code.
-  if (StartAttachListener) {
-    sprintf(path, ".java_pid%d", os::current_process_id());
-    strcpy(addr.sun_path, path);
-    ::unlink(path);
-    res = ::bind(listener, (struct sockaddr*)&addr, sizeof(addr));
-  }
-  if (res == -1) {
-    sprintf(path, "%s/.java_pid%d", os::get_temp_directory(), os::current_process_id());
-    strcpy(addr.sun_path, path);
-    ::unlink(path);
-    res = ::bind(listener, (struct sockaddr*)&addr, sizeof(addr)); 
-  }
+  sprintf(path, "%s/.java_pid%d", os::get_temp_directory(), os::current_process_id());
+  strcpy(addr.sun_path, path);
+  ::unlink(path);
+  res = ::bind(listener, (struct sockaddr*)&addr, sizeof(addr)); 
+
   if (res == -1) {
     RESTARTABLE(::close(listener), res);
     return -1;
@@ -188,7 +175,7 @@
   set_path(path);
 
   // put in listen mode and set permission 
-  if ((::listen(listener, 5) == -1) || (::chmod(path, S_IREAD|S_IWRITE) == -1)) {
+  if ((::listen(listener, 5) == -1) || (::chmod(path, S_IREAD|S_IWRITE) == -1) || (::chown(path,geteuid(),getegid()) == -1)) {
     RESTARTABLE(::close(listener), res);
     ::unlink(path);
     set_path(NULL);
@@ -264,19 +251,19 @@
   }
 
   // parse request
-                                                                                                   
+
   ArgumentIterator args(buf, (max_len)-left);
 
   // version already checked
   char* v = args.next();
-                                                                                                   
+
   char* name = args.next();
   if (name == NULL || strlen(name) > AttachOperation::name_length_max) {
     return NULL;
   }
 
   BsdAttachOperation* op = new BsdAttachOperation(name);
-                                                                                                   
+
   for (int i=0; i<AttachOperation::arg_count_max; i++) {
     char* arg = args.next();
     if (arg == NULL) {
@@ -376,7 +363,7 @@
 // default send buffer is sufficient to buffer everything. In the future
 // if there are operations that involves a very big reply then it the
 // socket could be made non-blocking and a timeout could be used.
-                                                                                                   
+
 void BsdAttachOperation::complete(jint result, bufferedStream* st) {
   JavaThread* thread = JavaThread::current();
   ThreadBlockInVM tbivm(thread);
@@ -456,15 +443,15 @@
   if (init_at_startup() || is_initialized()) {
     return false;               // initialized at startup or already initialized
   }
-  char fn[32];
-  sprintf(fn, ".attach_pid%d", os::current_process_id());
+  char path[PATH_MAX+1];	// socket file
   int ret;
   struct stat st;
-  RESTARTABLE(::stat(fn, &st), ret);
-  if (ret == -1) {
-    sprintf(fn, "/tmp/.attach_pid%d", os::current_process_id());
-    RESTARTABLE(::stat(fn, &st), ret);
-  }
+
+  sprintf(path, "%s/.attach_pid%d", os::get_temp_directory(), os::current_process_id());
+  fprintf(stdout, "Received SIGQUIT, looking for %s\n", path);
+
+  RESTARTABLE(::stat(path, &st), ret);
+
   if (ret == 0) {
     // simple check to avoid starting the attach mechanism when
     // a bogus user creates the file
