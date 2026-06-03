--- ui/gl/sync_control_vsync_provider.h.orig	2022-05-19 14:06:27 UTC
+++ ui/gl/sync_control_vsync_provider.h
@@ -31,7 +31,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   bool SupportGetVSyncParametersIfAvailable() const override;
 
   static constexpr bool IsSupported() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return true;
 #else
     return false;
@@ -46,7 +46,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
