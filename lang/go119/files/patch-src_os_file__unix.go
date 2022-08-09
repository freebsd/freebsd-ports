From 21a3e299aad894f744292d8cf1db4120efb3651f Mon Sep 17 00:00:00 2001
From: Yuval Pavel Zholkover <paulzhol@gmail.com>
Date: Sat, 30 Jul 2022 20:41:58 +0300
Subject: [PATCH] os: only add file descriptors which are set to non-blocking mode to the netpoller

Either ones where kind == kindNonBlock or those we've successfully called syscall.SetNonblock() on.
Restore blocking behavior if we detect an error registering with the netpoller and our flow was
successful in setting the inital syscall.SetNonblock().

Update #54100

Change-Id: I08934e4107c7fb36c15a7ca23ac880490b4df235

--- src/os/file_unix.go.orig	2022-08-01 22:45:57 UTC
+++ src/os/file_unix.go
@@ -168,18 +168,28 @@ func newFile(fd uintptr, name string, kind newFileKind
 		}
 	}
 
-	if err := f.pfd.Init("file", pollable); err != nil {
-		// An error here indicates a failure to register
-		// with the netpoll system. That can happen for
-		// a file descriptor that is not supported by
-		// epoll/kqueue; for example, disk files on
-		// Linux systems. We assume that any real error
-		// will show up in later I/O.
-	} else if pollable {
-		// We successfully registered with netpoll, so put
-		// the file into nonblocking mode.
-		if err := syscall.SetNonblock(fdi, true); err == nil {
+	clearNonBlock := false
+	if pollable {
+		if kind == kindNonBlock {
 			f.nonblock = true
+		} else if err := syscall.SetNonblock(fdi, true); err == nil {
+			f.nonblock = true
+			clearNonBlock = true
+		} else {
+			pollable = false
+		}
+	}
+
+	// An error here indicates a failure to register
+	// with the netpoll system. That can happen for
+	// a file descriptor that is not supported by
+	// epoll/kqueue; for example, disk files on
+	// Linux systems. We assume that any real error
+	// will show up in later I/O.
+	// We do restore the blocking behavior if it was set by us.
+	if pollErr := f.pfd.Init("file", pollable); pollErr != nil && clearNonBlock {
+		if err := syscall.SetNonblock(fdi, false); err == nil {
+			f.nonblock = false
 		}
 	}
 
