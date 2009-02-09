--- mono/metadata/class.c.orig	2008-11-01 01:58:37.000000000 -0300
+++ mono/metadata/class.c	2008-11-01 02:01:35.000000000 -0300
@@ -7449,7 +7449,10 @@
 gboolean
 mono_class_generic_sharing_enabled (MonoClass *class)
 {
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__FreeBSD__) && defined(__x86_64__)
+/* https://bugzilla.novell.com/show_bug.cgi?id=434457 */
+	static gboolean supported = FALSE;
+#elif defined(__i386__) || defined(__x86_64__)
 	static gboolean supported = TRUE;
 #else
 	/* Not supported by the JIT backends */
