--- src/butil/threading/platform_thread_freebsd.cc.orig	2026-02-23 02:11:29 UTC
+++ src/butil/threading/platform_thread_freebsd.cc
@@ -13,7 +13,6 @@
 #include "butil/safe_strerror_posix.h"
 #include "butil/threading/thread_id_name_manager.h"
 #include "butil/threading/thread_restrictions.h"
-#include "butil/tracked_objects.h"
 
 #if !defined(OS_NACL)
 #include <sys/resource.h>
@@ -46,7 +45,6 @@ void PlatformThread::SetName(const char* name) {
 // static
 void PlatformThread::SetName(const char* name) {
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
-  tracked_objects::ThreadData::InitializeThreadContext(name);
 
   SetNameSimple(name);
 }
