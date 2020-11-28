--- lib/bpf/src/libbpf.c.orig	2020-11-16 19:49:14 UTC
+++ lib/bpf/src/libbpf.c
@@ -30,18 +30,12 @@
 #include <linux/kernel.h>
 #include <linux/bpf.h>
 #include <linux/btf.h>
-#include <linux/filter.h>
 #include <linux/list.h>
 #include <linux/limits.h>
-#include <linux/perf_event.h>
-#include <linux/ring_buffer.h>
-#include <linux/version.h>
-#include <sys/epoll.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <sys/vfs.h>
 #include <sys/utsname.h>
 #include <sys/resource.h>
 #include <libelf.h>
@@ -72,9 +66,11 @@
 
 #define __printf(a, b)	__attribute__((format(printf, a, b)))
 
+#ifndef __FreeBSD__
 static struct bpf_map *bpf_object__add_map(struct bpf_object *obj);
 static const struct btf_type *
 skip_mods_and_typedefs(const struct btf *btf, __u32 id, __u32 *res_id);
+#endif /* !__FreeBSD__ */
 
 static int __base_pr(enum libbpf_print_level level, const char *format,
 		     va_list args)
@@ -108,6 +104,7 @@ void libbpf_print(enum libbpf_print_level level, const
 	va_end(args);
 }
 
+#ifndef __FreeBSD__
 static void pr_perm_msg(int err)
 {
 	struct rlimit limit;
@@ -8959,12 +8956,14 @@ bpf_object__find_map_by_offset(struct bpf_object *obj,
 {
 	return ERR_PTR(-ENOTSUP);
 }
+#endif /* !__FreeBSD__ */
 
 long libbpf_get_error(const void *ptr)
 {
 	return PTR_ERR_OR_ZERO(ptr);
 }
 
+#ifndef __FreeBSD__
 int bpf_prog_load(const char *file, enum bpf_prog_type type,
 		  struct bpf_object **pobj, int *prog_fd)
 {
@@ -10860,3 +10859,4 @@ void bpf_object__destroy_skeleton(struct bpf_object_sk
 	free(s->progs);
 	free(s);
 }
+#endif /* !__FreeBSD__ */
