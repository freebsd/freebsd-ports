--- third_party/perfetto/src/base/clock_snapshots.cc.orig	2025-03-24 20:50:14 UTC
+++ third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,7 @@ ClockSnapshotVector CaptureClockSnapshots() {
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&  \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD) &&  \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
     clockid_t id;
