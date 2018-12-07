--- src/common/os_auto_flush_linux.c.orig	2018-11-16 20:26:19 UTC
+++ src/common/os_auto_flush_linux.c
@@ -75,7 +75,7 @@ check_cpu_cache(const char *domain_path)
 		cpu_cache = -1;
 		goto end;
 	} else if (len == 0) {
-		errno = ENODATA;
+		errno = EINVAL;
 		ERR("read(%d, %p, %d) empty string",
 			domain_fd, domain_value,
 			DOMAIN_VALUE_LEN);
