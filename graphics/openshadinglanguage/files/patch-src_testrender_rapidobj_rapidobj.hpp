--- src/testrender/rapidobj/rapidobj.hpp.orig	2025-12-28 12:45:06 UTC
+++ src/testrender/rapidobj/rapidobj.hpp
@@ -61,6 +61,12 @@ OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
 #include <sys/stat.h>
 #include <unistd.h>
 
+#elif __FreeBSD__
+
+#include <fcntl.h>
+#include <sys/stat.h>
+#include <unistd.h>
+
 #endif
 
 #define RAPIDOBJ_VERSION_MAJOR 1
@@ -5200,6 +5206,111 @@ struct FileReader : Reader {
   private:
     int    m_fd = -1;
     off_t  m_offset{};
+    size_t m_size{};
+    char*  m_buffer{};
+};
+
+#elif __FreeBSD__
+
+inline auto AlignedAllocate(size_t size, size_t alignment)
+{
+    return static_cast<char*>(aligned_alloc(alignment, size));
+}
+
+struct AlignedDeleter final {
+    void operator()(void* ptr) const { free(ptr); }
+};
+
+class File final {
+  public:
+    File(const std::filesystem::path& filepath)
+    {
+        auto filepath_string = filepath.string();
+
+        if (-1 == stat(filepath_string.c_str(), &m_info)) {
+            m_error = std::error_code(errno, std::system_category());
+            return;
+        }
+
+        m_fd = open(filepath_string.c_str(), O_RDONLY);
+
+        if (-1 == m_fd) {
+            m_error = std::error_code(errno, std::system_category());
+        }
+    }
+    File(const File&)            = delete;
+    File& operator=(const File&) = delete;
+    File(File&&)                 = delete;
+    File& operator=(File&&)      = delete;
+    ~File() noexcept
+    {
+        if (m_fd != -1) {
+            close(m_fd);
+        }
+    }
+
+    explicit operator bool() const noexcept { return m_fd != -1; }
+    auto     handle() const noexcept { return m_fd; }
+    auto     size() const noexcept { return static_cast<size_t>(m_info.st_size); }
+    auto     error() const noexcept { return m_error; }
+
+  private:
+    int             m_fd = -1;
+    struct stat     m_info {};
+    std::error_code m_error{};
+};
+
+struct FileReader : Reader {
+    FileReader(const File& file) noexcept : m_fd{ file.handle() } {}
+
+    std::error_code ReadBlock(size_t offset, size_t size, char* buffer) override
+    {
+        assert(buffer);
+        assert(m_fd != -1);
+        assert(std::uintptr_t(buffer) % 4096 == 0);
+
+        ++m_num_requests;
+
+        auto t1 = std::chrono::steady_clock::now();
+
+        m_offset = offset;
+        m_size   = size;
+        m_buffer = buffer;
+
+        posix_fadvise(m_fd, offset, size, POSIX_FADV_WILLNEED);
+
+        auto t2 = std::chrono::steady_clock::now();
+
+        m_submit_time += t2 - t1;
+
+        return {};
+    }
+
+    ReadResult WaitForResult() override
+    {
+        auto t1 = std::chrono::steady_clock::now();
+
+        auto result = pread(m_fd, m_buffer, m_size, m_offset);
+
+        auto t2 = std::chrono::steady_clock::now();
+
+        m_wait_time += t2 - t1;
+
+        if (result < 0) {
+            auto error = std::error_code(errno, std::system_category());
+            return ReadResult{ 0, error };
+        }
+
+        auto bytes_read = static_cast<size_t>(result);
+
+        m_bytes_read += bytes_read;
+
+        return ReadResult{ bytes_read, std::error_code() };
+    }
+
+  private:
+    int    m_fd = -1;
+    size_t m_offset{};
     size_t m_size{};
     char*  m_buffer{};
 };
