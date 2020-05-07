--- lib/bpf/src/libbpf.c.orig	2020-03-12 19:57:29 UTC
+++ lib/bpf/src/libbpf.c
@@ -29,18 +29,12 @@
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
 #include <tools/libc_compat.h>
@@ -73,11 +67,13 @@
 
 #define __printf(a, b)	__attribute__((format(printf, a, b)))
 
+#ifndef __FreeBSD__
 static struct bpf_map *bpf_object__add_map(struct bpf_object *obj);
 static struct bpf_program *bpf_object__find_prog_by_idx(struct bpf_object *obj,
 							int idx);
 static const struct btf_type *
 skip_mods_and_typedefs(const struct btf *btf, __u32 id, __u32 *res_id);
+#endif /* !__FreeBSD__ */
 
 static int __base_pr(enum libbpf_print_level level, const char *format,
 		     va_list args)
@@ -111,6 +107,7 @@ void libbpf_print(enum libbpf_print_level level, const
 	va_end(args);
 }
 
+#ifndef __FreeBSD__
 static void pr_perm_msg(int err)
 {
 	struct rlimit limit;
@@ -8396,3 +8387,4 @@ void bpf_object__destroy_skeleton(struct bpf_object_sk
 	free(s->progs);
 	free(s);
 }
+#endif /* !__FreeBSD__ */
