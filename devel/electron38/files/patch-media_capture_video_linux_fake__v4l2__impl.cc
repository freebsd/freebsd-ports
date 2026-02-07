--- media/capture/video/linux/fake_v4l2_impl.cc.orig	2025-08-26 20:49:50 UTC
+++ media/capture/video/linux/fake_v4l2_impl.cc
@@ -570,7 +570,7 @@ int FakeV4L2Impl::close(int fd) {
   return kSuccessReturnValue;
 }
 
-int FakeV4L2Impl::ioctl(int fd, int request, void* argp) {
+int FakeV4L2Impl::ioctl(int fd, unsigned long request, void* argp) {
   base::AutoLock lock(lock_);
   auto device_iter = opened_devices_.find(fd);
   if (device_iter == opened_devices_.end())
