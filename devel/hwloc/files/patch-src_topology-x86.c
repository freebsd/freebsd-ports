--- src/topology-x86.c.orig	2017-04-19 15:19:38 UTC
+++ src/topology-x86.c
@@ -997,7 +997,14 @@ int hwloc_look_x86(struct hwloc_backend *backend, int 
   unsigned features[10] = { 0 };
   struct procinfo *infos = NULL;
   enum cpuid_type cpuid_type = unknown;
+#if defined HWLOC_FREEBSD_SYS && defined HAVE_CPUSET_SETID \
+ && __FreeBSD_version >= 1101000 && __FreeBSD_version < 1102000
+  /* Buffer overrun in cpuset_getid in FreeBSD 11.1 */
+  hwloc_x86_os_state_t os_state[2];
+#define os_state os_state[0]
+#else
   hwloc_x86_os_state_t os_state;
+#endif
   struct hwloc_binding_hooks hooks;
   struct hwloc_topology_support support;
   struct hwloc_topology_membind_support memsupport __hwloc_attribute_unused;
