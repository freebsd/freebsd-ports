--- src/efivar.c.orig	2014-10-15 15:48:49.000000000 +0200
+++ src/efivar.c	2015-01-19 15:41:34.000000000 +0100
@@ -16,11 +16,11 @@
  * along with this library.  If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <ctype.h>
 #include <fcntl.h>
 #include <popt.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/endian.h>
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -53,7 +53,7 @@ list_all_variables(void)
 	int rc;
 	while ((rc = efi_get_next_variable_name(&guid, &name)) > 0)
 		 printf(GUID_FORMAT "-%s\n",
-			guid->a, guid->b, guid->c, bswap_16(guid->d),
+			guid->a, guid->b, guid->c, bswap16(guid->d),
 			guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 			guid->e[4], guid->e[5], name);
 
@@ -142,7 +142,7 @@ show_variable(char *guid_name)
 	}
 
 	printf("GUID: "GUID_FORMAT "\n",
-			guid.a, guid.b, guid.c, bswap_16(guid.d),
+			guid.a, guid.b, guid.c, bswap16(guid.d),
 			guid.e[0], guid.e[1], guid.e[2], guid.e[3],
 			guid.e[4], guid.e[5]);
 	printf("Name: \"%s\"\n", name);
@@ -240,7 +240,7 @@ prepare_data(const char *filename, void 
 		goto err;
 
 	buflen = statbuf.st_size;
-	buf = mmap(NULL, buflen, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0);
+	buf = mmap(NULL, buflen, PROT_READ, MAP_PRIVATE, fd, 0);
 	if (!buf)
 		goto err;
 
@@ -338,7 +338,7 @@ int main(int argc, char *argv[])
 			{
 				printf("{"GUID_FORMAT"} {%s} %s %s\n",
 					guid->guid.a, guid->guid.b,
-					guid->guid.c, bswap_16(guid->guid.d),
+					guid->guid.c, bswap16(guid->guid.d),
 					guid->guid.e[0], guid->guid.e[1],
 					guid->guid.e[2], guid->guid.e[3],
 					guid->guid.e[4], guid->guid.e[5],
