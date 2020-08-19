--- jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.h.orig	2020-08-01 01:24:39 UTC
+++ jdk/src/solaris/native/sun/security/jgss/wrapper/NativeFunc.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2005, 2006, Oracle and/or its affiliates. All rights reserved.
+ * Copyright (c) 2005, 2020, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
  * This code is free software; you can redistribute it and/or modify it
@@ -265,6 +265,6 @@ typedef struct GSS_FUNCTION_TABLE {
 typedef GSS_FUNCTION_TABLE *GSS_FUNCTION_TABLE_PTR;
 
 /* global GSS function table */
-GSS_FUNCTION_TABLE_PTR ftab;
+extern GSS_FUNCTION_TABLE_PTR ftab;
 
 #endif
