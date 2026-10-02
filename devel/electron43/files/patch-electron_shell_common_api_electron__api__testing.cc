--- electron/shell/common/api/electron_api_testing.cc.orig	2026-10-01 11:00:40 UTC
+++ electron/shell/common/api/electron_api_testing.cc
@@ -27,7 +27,7 @@
 #include "ui/accessibility/platform/ax_platform.h"
 #include "v8/include/v8.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <glib.h>
 #elif BUILDFLAG(IS_MAC)
 #include <CoreFoundation/CoreFoundation.h>
@@ -239,7 +239,7 @@ struct SettleOutsideTask {
                                                  std::move(self->after_settle));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static gboolean OnIdle(gpointer data) {
     Run(base::WrapUnique(static_cast<SettleOutsideTask*>(data)));
     return G_SOURCE_REMOVE;
@@ -269,7 +269,7 @@ v8::Local<v8::Promise> SettlePromiseOutsideTask(
   auto state = std::make_unique<SettleOutsideTask>(SettleOutsideTask{
       gin_helper::Promise<void>(isolate), std::move(after_settle)});
   v8::Local<v8::Promise> handle = state->promise.GetHandle();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   g_idle_add(&SettleOutsideTask::OnIdle, state.release());
 #elif BUILDFLAG(IS_MAC)
   CFRunLoopTimerContext context = {0, state.release(), nullptr, nullptr,
