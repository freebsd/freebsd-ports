--- EdyValue.c.orig	Sat Jan  6 16:36:29 2007
+++ EdyValue.c	Sun Jan 21 02:36:09 2007
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include "libpasori.h"
+#include "libpasori_command.h"
 #define TRUE 1
 #define FALSE 0
 
@@ -19,21 +20,25 @@
         return (FALSE);
 }
 
-int main(void){
+int main(int argc, char **argv){
 	pasori* p;
 	felica* f;
 	int i;
-	int m;
-	int year, month, day;
+	unsigned int month, day;
 	uint8 b[16];
 	
-	p = pasori_open(NULL);
+	char* devpath = NULL;
+	if (argc == 2) {
+		devpath = argv[1];
+	}
+	p = pasori_open(devpath);
 	if(!p){
 		printf("error\n");
 		exit(-1);
 	}
 	pasori_init(p);
 	f = felica_polling(p,0xFE00,0,0);
+	if (f) {
 	printf("*** Edy Value ***\n");
 	i=0;
 		while(!felica_read_without_encryption02(f,0x170F,0,i,b)){
@@ -79,6 +84,8 @@
 		printf(" --> % 5d Yen (rest)   ",b[14]*256+b[15]);
 		printf("%02X%02X%02X\n",b[1],b[2],b[3]);
 		i++;
+	}
+	free(f);
 	}
 	pasori_close(p);
 	return 0;
