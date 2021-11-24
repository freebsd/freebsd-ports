--- gin/wrappable.cc.orig	2021-11-13 09:18:27 UTC
+++ gin/wrappable.cc
@@ -8,7 +8,7 @@
 #include "gin/object_template_builder.h"
 #include "gin/per_isolate_data.h"
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "components/crash/core/common/crash_key.h"
 #include "electron/shell/common/crash_keys.h"
 #endif
@@ -42,7 +42,7 @@ void WrappableBase::SecondWeakCallback(
     const v8::WeakCallbackInfo<WrappableBase>& data) {
   WrappableBase* wrappable = data.GetParameter();
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   WrapperInfo* wrapperInfo = static_cast<WrapperInfo*>(data.GetInternalField(0));
   std::string location = electron::crash_keys::GetCrashValueForGinWrappable(wrapperInfo);
 
