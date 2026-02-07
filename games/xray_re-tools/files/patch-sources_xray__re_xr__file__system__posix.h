--- sources/xray_re/xr_file_system_posix.h.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_file_system_posix.h
@@ -8,6 +8,29 @@
 
 namespace xray_re {
 
+class xr_mmap_reader_posix: public xr_reader {
+public:
+			xr_mmap_reader_posix();
+			xr_mmap_reader_posix(int fd, const void *data, size_t size);
+	virtual		~xr_mmap_reader_posix();
+
+private:
+	int m_fd;
+};
+
+class xr_file_writer_posix: public xr_writer {
+public:
+			xr_file_writer_posix();
+			xr_file_writer_posix(int fd);
+	virtual		~xr_file_writer_posix();
+	virtual void	w_raw(const void* src, size_t src_size);
+	virtual void	seek(size_t pos);
+	virtual size_t	tell();
+
+private:
+	int m_fd;
+};
+
 } // end of namespace xray_re
 
 #endif
