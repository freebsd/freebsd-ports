--- include/spdlog/common-inl.h.orig	2021-06-24 13:59:17 UTC
+++ include/spdlog/common-inl.h
@@ -60,7 +60,7 @@ SPDLOG_INLINE spdlog_ex::spdlog_ex(std::string msg)
 SPDLOG_INLINE spdlog_ex::spdlog_ex(const std::string &msg, int last_errno)
 {
     memory_buf_t outbuf;
-    fmt::format_system_error(outbuf, last_errno, msg);
+    fmt::format_system_error(outbuf, last_errno, msg.c_str());
     msg_ = fmt::to_string(outbuf);
 }
 
