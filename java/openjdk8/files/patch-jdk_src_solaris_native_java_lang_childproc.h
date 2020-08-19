--- jdk/src/solaris/native/java/lang/childproc.h.orig	2020-08-01 01:24:39 UTC
+++ jdk/src/solaris/native/java/lang/childproc.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2013, Oracle and/or its affiliates. All rights reserved.
+ * Copyright (c) 2013, 2020, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
  * This code is free software; you can redistribute it and/or modify it
@@ -119,7 +119,7 @@ typedef struct _SpawnInfo {
  * The cached and split version of the JDK's effective PATH.
  * (We don't support putenv("PATH=...") in native code)
  */
-const char * const *parentPathv;
+extern const char * const *parentPathv;
 
 ssize_t restartableWrite(int fd, const void *buf, size_t count);
 int restartableDup2(int fd_from, int fd_to);
