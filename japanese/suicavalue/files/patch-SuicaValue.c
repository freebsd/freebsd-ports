--- SuicaValue.c.orig	Sat Jan  6 16:36:31 2007
+++ SuicaValue.c	Sun Jan 21 03:05:30 2007
@@ -1,23 +1,30 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include "libpasori.h"
+#include "libpasori_command.h"
 
 int
-main(void){
+main(int argc, char **argv){
 	pasori* p;
 	felica* f;
 	int i;
-	int m;
 	int wk, wk2;
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
+	sleep(1);
 	f = felica_polling(p,0x0003,0,0);
+	if (f) {
 	printf("*** Suica Value ***\n");
 	i=0;
 		while(!felica_read_without_encryption02(f,0x090f,0,i,b)){
@@ -42,6 +49,8 @@
 			printf("  % 5d Yen        ",b[11]*256+b[10]);
 			printf("%02X%02X%02X%02X\n",b[12],b[13],b[14],b[15]);
 		i++;
+	}
+	free(f);
 	}
 	pasori_close(p);
 	return 0;
