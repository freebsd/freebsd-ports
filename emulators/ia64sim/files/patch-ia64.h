--- include/ia64.h.orig	Sun May  6 11:39:29 2001
+++ include/ia64.h	Sun May  6 11:35:10 2001
@@ -29,6 +29,7 @@
 #include <ctype.h>
 #include <string.h>
 #include <elf.h>
+#include <sys/elf64.h>
 
 #define TRUE 1
 #define FALSE 0
@@ -38,7 +39,7 @@
            0<=lo,hi<=63 and lo<=hi */
 
 #define BITS(x,lo,hi) (      \
-           (uint32)(x##.q >> lo) &   \
+           (uint32)(x.q >> lo) &   \
 	   ( (1<<(hi-lo+1)) - 1 )    \
 	   )
 
@@ -72,8 +73,8 @@
    uint8 b[8];
 } qword;
 
-#define HI(x)  (x##.d[1])
-#define LO(x)  (x##.d[0])
+#define HI(x)  (x.d[1])
+#define LO(x)  (x.d[0])
 
 typedef struct {
    qword dat;
