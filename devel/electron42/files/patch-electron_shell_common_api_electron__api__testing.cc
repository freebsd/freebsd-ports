--- electron/shell/common/api/electron_api_testing.cc.orig	2026-09-30 13:13:27 UTC
+++ electron/shell/common/api/electron_api_testing.cc
@@ -25,7 +25,7 @@
 #include "shell/common/node_includes.h"
 #include "v8/include/v8.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <glib.h>
 #elif BUILDFLAG(IS_MAC)
 #include <CoreFoundation/CoreFoundation.h>
@@ -233,7 +233,7 @@ struct SettleOutsideTask {
                                                  std::move(self->after_settle));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static gboolean OnIdle(gpointer data) {
     Run(base::WrapUnique(static_cast<SettleOutsideTask*>(data)));
     return G_SOURCE_REMOVE;
@@ -263,7 +263,7 @@ v8::Local<v8::Promise> SettlePromiseOutsideTask(
   auto state = std::make_unique<SettleOutsideTask>(SettleOutsideTask{
       gin_helper::Promise<void>(isolate), std::move(after_settle)});
   v8::Local<v8::Promise> handle = state->promise.GetHandle();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   g_idle_add(&SettleOutsideTask::OnIdle, state.release());
 #elif BUILDFLAG(IS_MAC)
   CFRunLoopTimerContext context = {0, state.release(), nullptr, nullptr,
