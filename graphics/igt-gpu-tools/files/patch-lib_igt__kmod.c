--- lib/igt_kmod.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_kmod.c
@@ -32,6 +32,7 @@
 #include "igt_sysfs.h"
 #include "igt_taints.h"
 
+#ifdef __linux__
 /**
  * SECTION:igt_kmod
  * @short_description: Wrappers around libkmod for module loading/unloading
@@ -853,3 +854,120 @@ void igt_kselftests(const char *module_name,
 
 	igt_kselftest_fini(&tst);
 }
+#elif defined(__FreeBSD__)
+struct kmod_module {
+	size_t size;
+};
+
+bool
+igt_kmod_is_loaded(const char *mod_name)
+{
+	return false;
+}
+
+void
+igt_kmod_list_loaded(void)
+{
+}
+
+bool
+igt_kmod_has_param(const char *mod_name, const char *param)
+{
+	return false;
+}
+
+int
+igt_kmod_load(const char *mod_name, const char *opts)
+{
+	return -ENOSYS;
+}
+
+int
+igt_kmod_unload(const char *mod_name, unsigned int flags)
+{
+	return -ENOSYS;
+}
+
+int
+igt_audio_driver_unload(char **whom)
+{
+	return -ENOSYS;
+}
+
+int
+igt_i915_driver_load(const char *opts)
+{
+	return -ENOSYS;
+}
+
+int
+igt_i915_driver_unload(void)
+{
+	return -ENOSYS;
+}
+
+int
+__igt_i915_driver_unload(char **whom)
+{
+	return -ENOSYS;
+}
+
+int
+igt_amdgpu_driver_load(const char *opts)
+{
+	return -ENOSYS;
+}
+
+int
+igt_amdgpu_driver_unload(void)
+{
+	return -ENOSYS;
+}
+
+void
+igt_kselftests(const char *module_name,
+    const char *module_options,
+    const char *result_option,
+    const char *filter)
+{
+}
+
+int
+igt_kselftest_init(struct igt_kselftest *tst,
+    const char *module_name)
+{
+	return -ENOSYS;
+}
+
+int
+igt_kselftest_begin(struct igt_kselftest *tst)
+{
+	return -ENOSYS;
+}
+
+void
+igt_kselftest_get_tests(struct kmod_module *kmod,
+    const char *filter,
+    struct igt_list_head *tests)
+{
+}
+
+int
+igt_kselftest_execute(struct igt_kselftest *tst,
+    struct igt_kselftest_list *tl,
+    const char *module_options,
+    const char *result)
+{
+	return -ENOSYS;
+}
+
+void
+igt_kselftest_end(struct igt_kselftest *tst)
+{
+}
+
+void
+igt_kselftest_fini(struct igt_kselftest *tst)
+{
+}
+#endif /* __linux__ */
