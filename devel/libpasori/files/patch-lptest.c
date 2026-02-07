--- src/lptest.c.orig	Mon Mar 20 09:12:58 2006
+++ src/lptest.c	Sun Jan 21 00:36:43 2007
@@ -2,24 +2,29 @@
 #include <stdlib.h>
 
 #include "libpasori.h"
+#include "libpasori_command.h"
 
 
 int
-main(void){
+main(int argc, char **argv){
 	pasori* p;
 	felica* f;
 	int i;
-	int m;
 	uint8 b[16];
 	
 	printf("lptest : start\n");
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
 	f = felica_polling(p,POLLING_ANY,0,0);
+	if (f) {
 	printf("read test\n");
 	for(i=0;i!=32;i++){
 		if(!felica_read_without_encryption02(f,0x090f,0,i,b)){
@@ -38,6 +43,8 @@
 			
 			
 		}
+	}
+	free(f);
 	}
 
 	pasori_close(p);
