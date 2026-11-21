--- electron/shell/common/api/electron_api_testing.cc.orig	2026-11-18 22:25:18 UTC
+++ electron/shell/common/api/electron_api_testing.cc
@@ -41,7 +41,7 @@
 #include "ui/accessibility/platform/ax_platform.h"
 #include "v8/include/v8.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <glib.h>
 #elif BUILDFLAG(IS_MAC)
 #include <CoreFoundation/CoreFoundation.h>
@@ -296,7 +296,7 @@ struct SettleOutsideTask {
                                                  std::move(self->after_settle));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static gboolean OnIdle(gpointer data) {
     Run(base::WrapUnique(static_cast<SettleOutsideTask*>(data)));
     return G_SOURCE_REMOVE;
@@ -326,7 +326,7 @@ v8::Local<v8::Promise> SettlePromiseOutsideTask(
   auto state = std::make_unique<SettleOutsideTask>(SettleOutsideTask{
       gin_helper::Promise<void>(isolate), std::move(after_settle)});
   v8::Local<v8::Promise> handle = state->promise.GetHandle();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   g_idle_add(&SettleOutsideTask::OnIdle, state.release());
 #elif BUILDFLAG(IS_MAC)
   CFRunLoopTimerContext context = {0, state.release(), nullptr, nullptr,
