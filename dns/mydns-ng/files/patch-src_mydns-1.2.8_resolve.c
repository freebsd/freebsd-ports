--- src/mydns/resolve.c.orig	2010-01-26 05:23:29.000000000 +0800
+++ src/mydns/resolve.c	2010-01-26 05:25:46.000000000 +0800
@@ -292,6 +292,7 @@
   register MYDNS_RR	*rr = NULL;
   taskexec_t		rv = 0;
   int			recurs = wildcard_recursion;
+  char			*savelabel = label;
 
 #if DEBUG_ENABLED && DEBUG_RESOLVE
   DebugX("resolve", 1, _("%s: resolve_label(%s, %s, %s, %s, %d)"), desctask(t),
@@ -312,6 +313,34 @@
     return (rv);
   }
 
+  /* No exact match */
+  /* Check for NS delegation */
+  while (*label) {
+    if ((rr = find_rr(t, soa, DNS_QTYPE_NS, label))) {
+      char *newfqdn;
+      if (LASTCHAR(label) == '.') {
+	newfqdn = STRDUP(label);
+      } else {
+	ASPRINTF(&newfqdn, "%s.%s", label, soa->origin);
+      }
+      rv = process_rr(t, AUTHORITY, qtype, newfqdn, soa, label, rr, level);
+      mydns_rr_free(rr);
+      RELEASE(newfqdn);
+      add_authority_ns(t, section, soa, label);
+#if DEBUG_ENABLED && DEBUG_RESOLVE
+      DebugX("resolve", 1, _("%s: resolve_label(%s) returning results %s"), desctask(t),
+	     fqdn, task_exec_name(rv));
+#endif
+      return (rv);
+    }
+    label = strchr(label, '.');
+    if (!label) break;
+    label++;
+  }
+  /* No NS delegation. */
+  /* Restore label, it may have been modified above */
+  label = savelabel;
+
   /*
    * No exact match.
    * If `label' isn't empty, replace the first part of the label with `*'
@@ -420,30 +449,6 @@
   }
 
  NOWILDCARDMATCH:
-  /* STILL no match - check for NS records for child delegation */
-  while (*label) {
-    if ((rr = find_rr(t, soa, DNS_QTYPE_NS, label))) {
-      char *newfqdn;
-      if (LASTCHAR(label) == '.') {
-	newfqdn = STRDUP(label);
-      } else {
-	ASPRINTF(&newfqdn, "%s.%s", label, soa->origin);
-      }
-      rv = process_rr(t, AUTHORITY, qtype, newfqdn, soa, label, rr, level);
-      mydns_rr_free(rr);
-      RELEASE(newfqdn);
-      add_authority_ns(t, section, soa, label);
-#if DEBUG_ENABLED && DEBUG_RESOLVE
-      DebugX("resolve", 1, _("%s: resolve_label(%s) returning results %s"), desctask(t),
-	     fqdn, task_exec_name(rv));
-#endif
-      return (rv);
-    }
-    label = strchr(label, '.');
-    if (!label) break;
-    label++;
-  }
-
   return (TASK_EXECUTED);
 }
 /*--- resolve_label() ---------------------------------------------------------------------------*/
