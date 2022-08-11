--- vendor/adb/compression_utils.h.orig	2022-06-09 20:52:06 UTC
+++ vendor/adb/compression_utils.h
@@ -95,7 +95,12 @@ struct NullDecoder final : public Decoder {
         void* p = output_buffer_.data();
         while (available_out > 0 && !input_buffer_.empty()) {
             size_t len = std::min(available_out, input_buffer_.front_size());
+#ifdef __FreeBSD__
+	    // TODO: Delete when FreeBSD 12.x goes EOL
+            p = (char *)memcpy(p, input_buffer_.front_data(), len) + len;
+#else
             p = mempcpy(p, input_buffer_.front_data(), len);
+#endif
             available_out -= len;
             input_buffer_.drop_front(len);
         }
@@ -119,7 +124,12 @@ struct NullEncoder final : public Encoder {
 
         while (available_out > 0 && !input_buffer_.empty()) {
             size_t len = std::min(available_out, input_buffer_.front_size());
+#ifdef __FreeBSD__
+	    // TODO: Delete when FreeBSD 12.x goes EOL
+            p = (char *)memcpy(p, input_buffer_.front_data(), len) + len;
+#else
             p = mempcpy(p, input_buffer_.front_data(), len);
+#endif
             available_out -= len;
             input_buffer_.drop_front(len);
         }
