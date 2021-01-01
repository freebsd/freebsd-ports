--- services/video_capture/broadcasting_receiver.cc.orig	2019-09-10 11:14:12 UTC
+++ services/video_capture/broadcasting_receiver.cc
@@ -40,7 +40,7 @@ void CloneSharedBufferHandle(const mojo::ScopedSharedB
 void CloneSharedBufferToRawFileDescriptorHandle(
     const mojo::ScopedSharedBufferHandle& source,
     media::mojom::VideoBufferHandlePtr* target) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   media::SharedMemoryHandleProvider provider;
   provider.InitFromMojoHandle(
       source->Clone(mojo::SharedBufferHandle::AccessMode::READ_WRITE));
@@ -174,7 +174,7 @@ void BroadcastingReceiver::BufferContext::
     ConvertRawFileDescriptorToSharedBuffer() {
   DCHECK(buffer_handle_->is_shared_memory_via_raw_file_descriptor());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   media::SharedMemoryHandleProvider provider;
   provider.InitAsReadOnlyFromRawFileDescriptor(
       std::move(buffer_handle_->get_shared_memory_via_raw_file_descriptor()
