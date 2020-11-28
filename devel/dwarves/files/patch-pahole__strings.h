--- pahole_strings.h.orig	2020-10-20 20:25:03 UTC
+++ pahole_strings.h
@@ -1,5 +1,5 @@
-#ifndef _STRINGS_H_
-#define _STRINGS_H_ 1
+#ifndef _PAHOLE_STRINGS_H_
+#define _PAHOLE_STRINGS_H_ 1
 /*
   SPDX-License-Identifier: GPL-2.0-only
 
@@ -28,4 +28,4 @@ static inline const char *strings__ptr(const struct st
 	return btf__str_by_offset(strings->btf, s);
 }
 
-#endif /* _STRINGS_H_ */
+#endif /* _PAHOLE_STRINGS_H_ */
