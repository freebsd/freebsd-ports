--- gl/inlstring.h.orig	Fri Aug 25 05:11:26 2000
+++ gl/inlstring.h	Fri Aug 25 05:11:36 2000
@@ -1,6 +1,6 @@
 /* Based on functions in linux/string.h */
 
-#include <linux/types.h>	/* for size_t */
+#include <sys/types.h>	/* for size_t */
 
 #if defined(__alpha__) || defined (NO_ASSEMBLY)
 
@@ -68,7 +68,7 @@ static inline void *
 	    "rep\n\t"
 	    "stosb"
   : :	    "a"(c), "D"(s), "c"(count)
-  :	    "cx", "di");
+  );
     return s;
 }
 
@@ -278,7 +278,7 @@ static inline void *
 			 "1:call __memcpyasm_regargs\n\t"
 			 "2:":
 			 :"S"(dest), "d"(src), "c"(n)
-			 :"ax", "0", "1", "2");
+			 :"ax");
     return dest;
 }
 
@@ -294,7 +294,7 @@ static inline void *
 			 "1:call __memcpyasm_regargs_aligned\n\t"
 			 "2:\n\t":
 			 :"S"(dest), "d"(src), "c"(n)
-			 :"ax", "0", "1", "2");
+			 :"ax");
     return dest;
 }
 
@@ -311,7 +311,7 @@ static inline void *
 			 "2:\n\t"
 			 :
 			 :"S"((long) dest), "d"((long) src), "c"((long) n)
-			 :"ax", "0", "1", "2");
+			 :"ax");
     return dest;
 }
 
