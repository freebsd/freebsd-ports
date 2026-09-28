--- libr/debug/p/native/bsd/bsd_debug.c.orig	2026-06-23 11:48:36 UTC
+++ libr/debug/p/native/bsd/bsd_debug.c
@@ -70,17 +70,37 @@ static void bsd_syscall_trace_set(R_UNUSED int pid, R_
 
 static void bsd_syscall_trace_set(R_UNUSED int pid, R_UNUSED bool enable) {
 #if defined(PT_GET_EVENT_MASK) && defined(PT_SET_EVENT_MASK) && defined(PTRACE_SCE) && defined(PTRACE_SCX)
+
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	int pe = 0;
+#elif defined(__NetBSD__)
 	ptrace_event_t pe = {0};
+#else
+#error "unsupported BSD variant for PT_GET_EVENT_MASK/PT_SET_EVENT_MASK"
+#endif
+
 	if (ptrace (PT_GET_EVENT_MASK, pid, (caddr_t)&pe, sizeof (pe)) == -1) {
 		return;
 	}
+
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	const int old = pe;
+#elif defined(__NetBSD__)
 	const int old = pe.pe_set_event;
+#endif
+
+    int mask = old;
 	if (enable) {
-		pe.pe_set_event |= PTRACE_SCE | PTRACE_SCX;
+		mask |= PTRACE_SCE | PTRACE_SCX;
 	} else {
-		pe.pe_set_event &= ~(PTRACE_SCE | PTRACE_SCX);
+		mask &= ~(PTRACE_SCE | PTRACE_SCX);
 	}
-	if (pe.pe_set_event != old) {
+	if (mask != old) {
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	pe = mask;
+#elif defined(__NetBSD__)
+	pe.pe_set_event = mask;
+#endif
 		(void)ptrace (PT_SET_EVENT_MASK, pid, (caddr_t)&pe, sizeof (pe));
 	}
 #endif
