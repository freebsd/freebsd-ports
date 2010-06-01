
$FreeBSD$

https://bugzilla.novell.com/show_bug.cgi?id=528830

--- mono/metadata/appdomain.c.orig
+++ mono/metadata/appdomain.c
@@ -2322,6 +2322,11 @@
 			/* The icall wrapper will execute the abort */
 			CloseHandle (thread_handle);
 			return;
+		} else if (!mono_thread_has_appdomain_ref (mono_thread_current (), domain) && !(mono_thread_interruption_requested ())) {
+			if (!domain->friendly_name) {
+				CloseHandle (thread_handle);
+				return;
+			}
 		}
 	}
 	CloseHandle (thread_handle);
