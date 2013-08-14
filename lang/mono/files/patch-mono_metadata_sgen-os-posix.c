
$FreeBSD$

https://bugzilla.xamarin.com/show_bug.cgi?id=13604
https://github.com/mono/mono/commit/2c45af25e2a027d749feef771a83a3c9c731f4aa

--- mono/metadata/sgen-os-posix.c.orig
+++ mono/metadata/sgen-os-posix.c
@@ -57,7 +57,14 @@
 #endif
 	gpointer stack_start;
 
-	g_assert (info->doing_handshake);
+	/*
+	 * It's possible that a dying thread is parked via
+	 * sgen_park_current_thread_if_doing_handshake(), and, while parked, STW tries to
+	 * suspend it again.  In that case doing_handshake will not be set anymore, and the
+	 * "nested" suspend must be ignored.
+	 */
+	if (!info->doing_handshake)
+		return;
 
 	info->stopped_domain = mono_domain_get ();
 	info->stopped_ip = context ? (gpointer) ARCH_SIGCTX_IP (context) : NULL;
