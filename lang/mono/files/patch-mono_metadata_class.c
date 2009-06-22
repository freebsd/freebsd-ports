
$FreeBSD$

--- mono/metadata/class.c.orig
+++ mono/metadata/class.c
@@ -7648,7 +7648,10 @@
 gboolean
 mono_class_generic_sharing_enabled (MonoClass *class)
 {
-#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || defined(__mono_ppc__)
+#if defined(__FreeBSD__) && defined(__x86_64__)
+	/* https://bugzilla.novell.com/show_bug.cgi?id=434457 */
+	static gboolean supported = FALSE;
+#elif defined(__i386__) || defined(__x86_64__) || defined(__arm__) || defined(__mono_ppc__)
 	static gboolean supported = TRUE;
 #else
 	/* Not supported by the JIT backends */
