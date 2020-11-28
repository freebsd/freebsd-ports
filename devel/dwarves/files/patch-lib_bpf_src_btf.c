--- lib/bpf/src/btf.c.orig	2020-11-16 19:49:14 UTC
+++ lib/bpf/src/btf.c
@@ -1,8 +1,7 @@
 // SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause)
 /* Copyright (c) 2018 Facebook */
 
-#include <byteswap.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -22,6 +21,12 @@
 #include "libbpf_internal.h"
 #include "hashmap.h"
 
+#ifdef __FreeBSD__
+#define	bswap_16(x)	bswap16(x)
+#define	bswap_32(x)	bswap32(x)
+#define	bswap_64(x)	bswap64(x)
+#endif
+
 #define BTF_MAX_NR_TYPES 0x7fffffffU
 #define BTF_MAX_STR_OFFSET 0x7fffffffU
 
@@ -519,12 +524,12 @@ int btf__set_pointer_size(struct btf *btf, size_t ptr_
 
 static bool is_host_big_endian(void)
 {
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 	return false;
-#elif __BYTE_ORDER == __BIG_ENDIAN
+#elif _BYTE_ORDER == _BIG_ENDIAN
 	return true;
 #else
-# error "Unrecognized __BYTE_ORDER__"
+# error "Unrecognized _BYTE_ORDER"
 #endif
 }
 
@@ -1080,6 +1085,7 @@ struct btf *btf__parse_split(const char *path, struct 
 	return btf_parse(path, base_btf, NULL);
 }
 
+#ifndef __FreeBSD__
 static int compare_vsi_off(const void *_a, const void *_b)
 {
 	const struct btf_var_secinfo *a = _a;
@@ -1223,6 +1229,7 @@ done:
 	free(log_buf);
 	return err;
 }
+#endif /* !FreeBSD */
 
 int btf__fd(const struct btf *btf)
 {
@@ -1318,6 +1325,7 @@ const char *btf__name_by_offset(const struct btf *btf,
 	return btf__str_by_offset(btf, offset);
 }
 
+#ifndef __FreeBSD__
 int btf__get_from_id(__u32 id, struct btf **btf)
 {
 	struct bpf_btf_info btf_info = { 0 };
@@ -1381,6 +1389,7 @@ exit_free:
 
 	return err;
 }
+#endif /* !FreeBSD */
 
 int btf__get_map_kv_tids(const struct btf *btf, const char *map_name,
 			 __u32 expected_key_size, __u32 expected_value_size,
@@ -4559,6 +4568,7 @@ static int btf_dedup_remap_types(struct btf_dedup *d)
 	return 0;
 }
 
+#ifndef __FreeBSD__
 /*
  * Probe few well-known locations for vmlinux kernel image and try to load BTF
  * data out of it to use for target BTF.
@@ -4609,3 +4619,4 @@ struct btf *libbpf_find_kernel_btf(void)
 	pr_warn("failed to find valid kernel BTF\n");
 	return ERR_PTR(-ESRCH);
 }
+#endif /* !FreeBSD */
