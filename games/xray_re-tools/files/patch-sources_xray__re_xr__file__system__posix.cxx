--- sources/xray_re/xr_file_system_posix.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_file_system_posix.cxx
@@ -1,3 +1,288 @@
+#include <string>
+#include <cstdlib>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/uio.h>
+#include <sys/mman.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <string.h>
+#include <unistd.h>
 #include "xr_file_system_posix.h"
+#include "xr_string_utils.h"
 
 using namespace xray_re;
+
+static char *normalize_path(const char *path)
+{
+	char *temp = strdup(path);
+
+	for (int i = 0; temp[i]; i++) {
+		if (temp[i] == '\\')
+			temp[i] = '/';
+	}
+	return temp;	// don't forget to free it!
+}
+
+bool xr_file_system::create_folder(const char* path) const
+{
+	char *temp = normalize_path(path);
+
+	if (read_only()) {
+		dbg("fs_ro: creating folder %s", temp);
+		return true;
+	}
+	bool done = mkdir(temp, 0777) == 0 || errno == EEXIST;
+	free(temp);
+	return done;
+}
+
+bool xr_file_system::create_path(const char* path) const
+{
+	char *temp = normalize_path(path);
+
+	if (read_only()) {
+		dbg("fs_ro: creating path %s", temp);
+		return true;
+	}
+
+	bool done = false;
+	for (char* p = temp; *p != 0; ++p) {
+		if (*p != '/')
+			continue;
+		*p = 0;
+		struct stat sb;
+		stat(temp, &sb);
+		if (stat(temp, &sb) == -1 && errno == ENOENT) {
+			if (mkdir(temp, 0777) == -1 && errno != EEXIST) {
+				goto out;
+			}
+		} else if ((sb.st_mode & S_IFDIR) == 0) {
+			goto out;
+		}
+		*p = '/';
+	}
+	done = mkdir(temp, 0777) == 0 || errno == EEXIST;
+out:
+	free(temp);
+	return done;
+}
+
+#define _MAX_FNAME	256
+#define _MAX_DIR	_MAX_FNAME
+#define _MAX_EXT	_MAX_FNAME
+
+void xr_file_system::split_path(const char* path, std::string* folder,
+		std::string* name, std::string* extension)
+{
+	char *_dir, *_name, *_ext;
+	char *temp = strdup(path);
+
+	// find last dot
+	char *last = strrchr(temp, '.');
+	if (last) {
+		_ext = last;
+		if (extension) {
+			extension->assign(_ext);
+			xr_strlwr(*extension);
+		}
+		*_ext = '\0';
+	}
+
+	// find last backslash or slash
+	last = strrchr(temp, '\\');
+	char *last2 = strrchr(temp, '/');
+	if (last2 > last)
+		last = last2;
+
+	if (last) {
+		_dir = temp;
+		*last++ = '\0';
+		_name = last;
+	} else {
+		_dir = "";
+		_name = temp;
+	}
+
+	if (folder) {
+		folder->assign(_dir);
+		xr_strlwr(*folder);
+	}
+	if (name) {
+		name->assign(_name);
+		xr_strlwr(*name);
+	}
+	free(temp);
+}
+
+bool xr_file_system::folder_exist(const char* path)
+{
+	char *temp = normalize_path(path);
+
+	struct stat sb;
+	bool ret = stat(temp, &sb) == -1 || (sb.st_mode & S_IFDIR) == 0;
+	free(temp);
+	return !ret;
+}
+
+bool xr_file_system::file_exist(const char* path)
+{
+	char *temp = normalize_path(path);
+
+	struct stat sb;
+	bool ret = stat(path, &sb) == -1 || (sb.st_mode & S_IFDIR) != 0;
+	free(temp);
+	return !ret;
+}
+
+size_t xr_file_system::file_length(const char* path)
+{
+	char *temp = normalize_path(path);
+
+	struct stat sb;
+	size_t len = (stat(path, &sb) == 0) ? sb.st_size : 0;
+	free(temp);
+	return len;
+}
+
+uint32_t xr_file_system::file_age(const char* path)
+{
+	char *temp = normalize_path(path);
+
+	struct stat st;
+	time_t age = (stat(path, &st) == 0) ? st.st_mtime : 0;
+	free(temp);
+	return uint32_t(age);
+}
+
+#if 0
+bool xr_file_system::copy_file(const char* src_path, const char* tgt_path) const
+{
+	if (read_only()) {
+		dbg("fs_ro: copying %s to %s", src_path, tgt_path);
+		return true;
+	}
+	return CopyFileA(src_path, tgt_path, FALSE) != FALSE;
+}
+#endif
+
+xr_reader* xr_file_system::r_open(const char* path) const
+{
+	char *temp = normalize_path(path);
+
+	struct stat sb;
+
+	if (stat(temp, &sb) == -1) {
+		free(temp);
+		return 0;
+	}
+	size_t len = sb.st_size;
+
+	int fd = open(temp, O_RDONLY);
+	if (fd == -1) {
+		free(temp);
+		return 0;
+	}
+
+	xr_reader* r = 0;
+
+	void *data;
+	if (len < getpagesize()) {
+		uint8_t *data = (uint8_t *)malloc(len);
+		if (data != NULL) {
+			if (read(fd, data, len) == len) {
+				r = new xr_temp_reader(data, len);
+			} else {
+				free(data);
+			}
+		}
+		close(fd);
+		free(temp);
+		return r;
+	}
+
+	data = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
+
+	if (data != MAP_FAILED) {
+		r = new xr_mmap_reader_posix(fd, data, len);
+		if (r) {
+			free(temp);
+			return r;
+		}
+		munmap(data, len);
+	}
+
+	close(fd);
+
+	return 0;
+}
+
+xr_writer* xr_file_system::w_open(const char* path, bool ignore_ro) const
+{
+	char *temp = normalize_path(path);
+
+	if (!ignore_ro && read_only()) {
+		dbg("fs_ro: writing %s", temp);
+		free(temp);
+		return new xr_fake_writer();
+	}
+
+	int fd = open(temp, O_WRONLY | O_CREAT, 0666);
+	if (fd == -1) {
+		if(errno == ENOENT) {
+			std::string folder;
+			split_path(temp, &folder);
+			if (!create_path(folder))
+				return 0;
+			return w_open(temp, ignore_ro);
+		}
+		else
+			return 0;
+	}
+	xr_writer* w = new xr_file_writer_posix(fd);
+	if (w == 0)
+		close(fd);
+	return w;
+}
+
+xr_mmap_reader_posix::xr_mmap_reader_posix(): m_fd(-1) {}
+
+xr_mmap_reader_posix::xr_mmap_reader_posix(int fd, const void* data, size_t size):
+	m_fd(fd)
+{
+	m_next = m_p = m_data = static_cast<const uint8_t*>(data);
+	m_end = m_data + size;
+}
+
+xr_mmap_reader_posix::~xr_mmap_reader_posix()
+{
+	assert(m_data != 0);
+	assert(m_fd != -1);
+	munmap(const_cast<uint8_t*>(m_data), m_end - m_data);
+	close(m_fd);
+}
+
+xr_file_writer_posix::xr_file_writer_posix(): m_fd(-1) {}
+
+xr_file_writer_posix::xr_file_writer_posix(int fd): m_fd(fd) {}
+
+xr_file_writer_posix::~xr_file_writer_posix()
+{
+	close(m_fd);
+}
+
+void xr_file_writer_posix::w_raw(const void* data, size_t size)
+{
+	xr_assert(write(m_fd, data, size) == size);
+}
+
+void xr_file_writer_posix::seek(size_t pos)
+{
+	off_t new_pos = lseek(m_fd, (off_t)pos, SEEK_SET);
+	xr_assert(pos == (size_t)new_pos);
+}
+
+size_t xr_file_writer_posix::tell()
+{
+	return lseek(m_fd, 0, SEEK_CUR);
+}
