--- ui/gl/sync_control_vsync_provider.h.orig	2019-09-10 10:43:23 UTC
+++ ui/gl/sync_control_vsync_provider.h
@@ -26,11 +26,11 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   bool SupportGetVSyncParametersIfAvailable() const override;
 
   static constexpr bool IsSupported() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return true;
 #else
     return false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   }
 
  protected:
@@ -41,7 +41,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
@@ -52,7 +52,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   // from configuration change (monitor reconfiguration, moving windows
   // between monitors, suspend and resume, etc.).
   base::queue<base::TimeDelta> last_computed_intervals_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   DISALLOW_COPY_AND_ASSIGN(SyncControlVSyncProvider);
 };
