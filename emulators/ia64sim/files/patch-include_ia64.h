--- include/ia64.h.orig	2000-03-09 00:57:11 UTC
+++ include/ia64.h
@@ -29,6 +29,7 @@ benefit from your work.	
 #include <ctype.h>
 #include <string.h>
 #include <elf.h>
+#include <sys/elf64.h>
 
 #define TRUE 1
 #define FALSE 0
@@ -38,7 +39,7 @@ benefit from your work.	
            0<=lo,hi<=63 and lo<=hi */
 
 #define BITS(x,lo,hi) (      \
-           (uint32)(x##.q >> lo) &   \
+           (uint32)(x.q >> lo) &   \
 	   ( (1<<(hi-lo+1)) - 1 )    \
 	   )
 
@@ -72,8 +73,8 @@ typedef union {
    uint8 b[8];
 } qword;
 
-#define HI(x)  (x##.d[1])
-#define LO(x)  (x##.d[0])
+#define HI(x)  (x.d[1])
+#define LO(x)  (x.d[0])
 
 typedef struct {
    qword dat;
