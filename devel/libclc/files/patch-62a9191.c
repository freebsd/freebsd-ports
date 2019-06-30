From 62a9191b606abdab8e2607d945628fa90d9664c1 Mon Sep 17 00:00:00 2001
From: Jan Vesely <jan.vesely@rutgers.edu>
Date: Fri, 3 Aug 2018 15:14:08 +0000
Subject: [PATCH] amdgcn: Use __constant AS for amdgcn builtins.

Fixes build after clang r338707.
Reviewer: Matthew.Arsenault@amd.com
Signed-off-by: Jan Vesely <jan.vesely@rutgers.edu>

git-svn-id: https://llvm.org/svn/llvm-project/libclc/trunk@338898 91177308-0d34-0410-b5e6-96231b3b80d8
---
 amdgcn-amdhsa/lib/workitem/get_global_size.cl | 4 +++-
 amdgcn-amdhsa/lib/workitem/get_local_size.cl  | 4 +++-
 amdgcn/lib/workitem/get_global_offset.cl      | 4 +++-
 amdgcn/lib/workitem/get_work_dim.cl           | 4 +++-
 4 files changed, 12 insertions(+), 4 deletions(-)

diff --git a/amdgcn-amdhsa/lib/workitem/get_global_size.cl b/amdgcn-amdhsa/lib/workitem/get_global_size.cl
index 2289615..392cd08 100644
--- amdgcn-amdhsa/lib/workitem/get_global_size.cl
+++ amdgcn-amdhsa/lib/workitem/get_global_size.cl
@@ -1,6 +1,8 @@
 #include <clc/clc.h>
 
-#if __clang_major__ >= 7
+#if __clang_major__ >= 8
+#define CONST_AS __constant
+#elif __clang_major__ >= 7
 #define CONST_AS __attribute__((address_space(4)))
 #else
 #define CONST_AS __attribute__((address_space(2)))
diff --git a/amdgcn-amdhsa/lib/workitem/get_local_size.cl b/amdgcn-amdhsa/lib/workitem/get_local_size.cl
index 034c6d9..64d1cf4 100644
--- amdgcn-amdhsa/lib/workitem/get_local_size.cl
+++ amdgcn-amdhsa/lib/workitem/get_local_size.cl
@@ -1,6 +1,8 @@
 #include <clc/clc.h>
 
-#if __clang_major__ >= 7
+#if __clang_major__ >= 8
+#define CONST_AS __constant
+#elif __clang_major__ >= 7
 #define CONST_AS __attribute__((address_space(4)))
 #else
 #define CONST_AS __attribute__((address_space(2)))
diff --git a/amdgcn/lib/workitem/get_global_offset.cl b/amdgcn/lib/workitem/get_global_offset.cl
index 0c2b948..0a87cd2 100644
--- amdgcn/lib/workitem/get_global_offset.cl
+++ amdgcn/lib/workitem/get_global_offset.cl
@@ -1,6 +1,8 @@
 #include <clc/clc.h>
 
-#if __clang_major__ >= 7
+#if __clang_major__ >= 8
+#define CONST_AS __constant
+#elif __clang_major__ >= 7
 #define CONST_AS __attribute__((address_space(4)))
 #else
 #define CONST_AS __attribute__((address_space(2)))
diff --git a/amdgcn/lib/workitem/get_work_dim.cl b/amdgcn/lib/workitem/get_work_dim.cl
index 8eb81ba..3add9b6 100644
--- amdgcn/lib/workitem/get_work_dim.cl
+++ amdgcn/lib/workitem/get_work_dim.cl
@@ -1,6 +1,8 @@
 #include <clc/clc.h>
 
-#if __clang_major__ >= 7
+#if __clang_major__ >= 8
+#define CONST_AS __constant
+#elif __clang_major__ >= 7
 #define CONST_AS __attribute__((address_space(4)))
 #else
 #define CONST_AS __attribute__((address_space(2)))
