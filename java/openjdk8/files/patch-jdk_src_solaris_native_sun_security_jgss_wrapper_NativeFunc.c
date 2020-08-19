--- jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.c.orig	2020-08-01 01:24:39 UTC
+++ jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2005, 2012, Oracle and/or its affiliates. All rights reserved.
+ * Copyright (c) 2005, 2020, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
  * This code is free software; you can redistribute it and/or modify it
@@ -27,6 +27,9 @@
 #include <stdlib.h>
 #include <dlfcn.h>
 #include "NativeFunc.h"
+
+/* global GSS function table */
+GSS_FUNCTION_TABLE_PTR ftab;
 
 /* standard GSS method names (ordering is from mapfile) */
 static const char RELEASE_NAME[]                = "gss_release_name";
