--- raop_play/aexcl_lib.h.orig	2005-12-16 14:17:01 UTC
+++ raop_play/aexcl_lib.h
@@ -1,5 +1,5 @@
 #include <stdio.h>
-#include <asm/types.h>
+#include <sys/types.h>
 #include <sys/time.h>
 #include <time.h>
 #include <stdlib.h>
@@ -35,6 +35,9 @@
 #define END_C_DECLS
 #endif
 
+#define __u8 u_int8_t
+#define __u16 u_int16_t
+#define __u32 u_int32_t
 
 BEGIN_C_DECLS
 
@@ -75,7 +78,6 @@ static inline int realloc_memory(void **
 		}
 		n=n<<1;
 	}
-	newsize=newsize;
 	np=realloc(*p,newsize);
 	if(!np){
 		ERRMSG("%s: realloc failed: %s\n",func,strerror(errno));
