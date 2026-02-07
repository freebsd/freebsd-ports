--- daemons/ir_remote.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/ir_remote.c
@@ -490,7 +490,7 @@ int write_message(char *buffer, size_t size, const cha
 {
 	int len;
 
-	len = snprintf(buffer, size, "%016llx %02x %s%s %s\n", code, reps, button_name, button_suffix, remote_name);
+	len = snprintf(buffer, size, "%016llx %02x %s%s %s\n", (unsigned long long)code, reps, button_name, button_suffix, remote_name);
 
 	return len;
 }
