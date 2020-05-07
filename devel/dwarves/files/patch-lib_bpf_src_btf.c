--- lib/bpf/src/btf.c.orig	2020-03-12 19:57:29 UTC
+++ lib/bpf/src/btf.c
@@ -436,6 +436,7 @@ done:
 	return btf;
 }
 
+#ifndef __FreeBSD__
 static bool btf_check_endianness(const GElf_Ehdr *ehdr)
 {
 #if __BYTE_ORDER == __LITTLE_ENDIAN
@@ -684,6 +685,7 @@ done:
 	free(log_buf);
 	return err;
 }
+#endif /* !FreeBSD */
 
 int btf__fd(const struct btf *btf)
 {
@@ -704,6 +706,7 @@ const char *btf__name_by_offset(const struct btf *btf,
 		return NULL;
 }
 
+#ifndef __FreeBSD__
 int btf__get_from_id(__u32 id, struct btf **btf)
 {
 	struct bpf_btf_info btf_info = { 0 };
@@ -767,6 +770,7 @@ exit_free:
 
 	return err;
 }
+#endif /* !FreeBSD */
 
 int btf__get_map_kv_tids(const struct btf *btf, const char *map_name,
 			 __u32 expected_key_size, __u32 expected_value_size,
@@ -2936,6 +2940,7 @@ static int btf_dedup_remap_types(struct btf_dedup *d)
 	return 0;
 }
 
+#ifndef __FreeBSD__
 static struct btf *btf_load_raw(const char *path)
 {
 	struct btf *btf;
@@ -3021,3 +3026,4 @@ struct btf *libbpf_find_kernel_btf(void)
 	pr_warn("failed to find valid kernel BTF\n");
 	return ERR_PTR(-ESRCH);
 }
+#endif /* !FreeBSD */
