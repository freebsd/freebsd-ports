--- clang/test/Driver/fsanitize.c.orig	2021-06-28 16:23:38 UTC
+++ clang/test/Driver/fsanitize.c
@@ -689,7 +689,13 @@
 // RUN: %clang -target x86_64-unknown-cloudabi -fsanitize=safe-stack %s -### 2>&1 | FileCheck %s -check-prefix=SAFESTACK-CLOUDABI
 // SAFESTACK-CLOUDABI: "-fsanitize=safe-stack"
 
+// RUN: %clang -target x86_64--freebsd -fsanitize=kernel-address %s -### 2>&1 | FileCheck %s -check-prefix=KERNEL-ADDRESS-FREEBSD
+// RUN: %clang -target aarch64--freebsd -fsanitize=kernel-address %s -### 2>&1 | FileCheck %s -check-prefix=KERNEL-ADDRESS-FREEBSD
+// KERNEL-ADDRESS-FREEBSD: "-fsanitize=kernel-address"
 
+// RUN: %clang -target x86_64--freebsd -fsanitize=kernel-memory %s -### 2>&1 | FileCheck %s -check-prefix=KERNEL-MEMORY-FREEBSD
+// RUN: %clang -target aarch64--freebsd -fsanitize=kernel-memory %s -### 2>&1 | FileCheck %s -check-prefix=KERNEL-MEMORY-FREEBSD
+// KERNEL-MEMORY-FREEBSD: "-fsanitize=kernel-memory"
 
 // * NetBSD; please keep ordered as in Sanitizers.def *
 
