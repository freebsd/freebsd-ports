--- jdk/src/solaris/native/java/lang/childproc.c.orig	2020-08-01 01:24:39 UTC
+++ jdk/src/solaris/native/java/lang/childproc.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2013, Oracle and/or its affiliates. All rights reserved.
+ * Copyright (c) 2013, 2020, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
  * This code is free software; you can redistribute it and/or modify it
@@ -33,6 +33,7 @@
 
 #include "childproc.h"
 
+const char * const *parentPathv;
 
 ssize_t
 restartableWrite(int fd, const void *buf, size_t count)
