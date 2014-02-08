From 952b046ba5bc99986f747729681914e21f8fb8b0 Mon Sep 17 00:00:00 2001
From: "Bradley T. Hughes" <bradley.hughes@nokia.com>
Date: Wed, 30 May 2012 11:49:40 +0200
Subject: [PATCH] Compile with clang's libc++

An overload for std::swap() what works with std::pair<A,B> is included
in libc++ (but not libstdc++). Avoid ambiguity in HashTable.h by
omitting the version there and using the std::swap() version.

Collector.cpp needs to include pthread.h directly, as it is not
automatically included by libc++'s headers (libstdc++ does pull in
pthread.h though).

Cherry-picked from qtscript/48baeef0766ba145d26d374561e152b40245f3b8.

Change-Id: I4dc88638ce8553bb97037b841fc6cc5e8c9911e2
Reviewed-by: Thiago Macieira <thiago.macieira@intel.com>
---
 src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp | 2 ++
 src/3rdparty/javascriptcore/JavaScriptCore/wtf/HashTable.h       | 4 ++--
 2 files changed, 4 insertions(+), 2 deletions(-)

diff --git a/src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp b/src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp
index 6af1784..711949b 100644
--- src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp
+++ src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp
@@ -52,6 +52,8 @@
 #include <mach/task.h>
 #include <mach/thread_act.h>
 #include <mach/vm_map.h>
+// clang's libc++ headers does not pull in pthread.h (but libstdc++ does)
+#include <pthread.h>
 
 #elif OS(WINDOWS)
 
-- 
1.8.4

