--- src/efivarfs.c.orig	2015-01-19 15:38:34.000000000 +0100
+++ src/efivarfs.c	2015-01-19 15:40:15.000000000 +0100
@@ -18,15 +18,15 @@
 
 #include <errno.h>
 #include <fcntl.h>
-#include <linux/magic.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
+#include <sys/mount.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/uio.h>
-#include <sys/vfs.h>
 #include <unistd.h>
 
 #include "lib.h"
@@ -66,7 +66,7 @@ efivarfs_probe(void)
 #define make_efivarfs_path(str, guid, name) ({				\
 		asprintf(str, EFIVARS_PATH "%s-" GUID_FORMAT,		\
 			name, (guid).a, (guid).b, (guid).c,		\
-			bswap_16((guid).d),				\
+			bswap16((guid).d),				\
 			(guid).e[0], (guid).e[1], (guid).e[2],		\
 			(guid).e[3], (guid).e[4], (guid).e[5]);		\
 	})
