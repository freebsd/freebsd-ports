--- lz4jsoncat.c.orig	2025-06-24 19:59:38 UTC
+++ lz4jsoncat.c
@@ -29,7 +29,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #ifndef __APPLE__
-#include <endian.h>
+#	if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFlyBSD__)
+#include <sys/endian.h>
+#endif
 #else
 #define htole32(x) x /* assume apple targets are little endian */
 #endif
@@ -38,8 +40,8 @@ int main(int ac, char **av)
 
 int main(int ac, char **av)
 {
-	while (*++av) {
-		int fd = open(*av, O_RDONLY);
+	while (--ac) {
+		int fd = open(*++av, O_RDONLY);
 		if (fd < 0) {
 			perror(*av);
 			continue;
@@ -55,7 +57,7 @@ int main(int ac, char **av)
 		}
 
 		char *map = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
-		if (map == (char *)-1) {
+		if (map == MAP_FAILED) {
 			perror(*av);
 			exit(1);
 		}
@@ -63,7 +65,7 @@ int main(int ac, char **av)
 			fprintf(stderr, "%s: not a mozLZ4a file\n", *av);
 			exit(1);
 		}
-		size_t outsz = htole32(*(uint32_t *) (map + 8));
+		ssize_t outsz = htole32(*(uint32_t *) (map + 8));
 		char *out = malloc(outsz);
 		if (!out) {
 			fprintf(stderr, "Cannot allocate memory\n");
@@ -87,6 +89,3 @@ int main(int ac, char **av)
 	}
 	return 0;
 }
-
-
-
