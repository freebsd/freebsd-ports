--- src/lpdump.c.orig	Tue May 16 02:55:42 2006
+++ src/lpdump.c	Sat Jan 20 23:04:08 2007
@@ -1,8 +1,10 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 
 #include "libpasori.h"
+#include "libpasori_command.h"
 
 void
 mydump(uint8 *p,int size){
@@ -96,7 +98,6 @@
 	uint16 area_end[60];
 	uint16 area_count;
 	uint16 servicecode[128];
-	int servicecode_area[128];
 	uint16 servicecode_count;
 	uint16 t;
 	uint16 idx;
@@ -166,7 +167,7 @@
 	uint8 resp[256];
 	uint16 sc[4];
 	int sc_count;
-	int i,j;
+	int i;
 
 	cmd[0] = 0x0c;
 	memcpy(&cmd[1],f->IDm,8);
@@ -188,14 +189,15 @@
 }
 
 int
-main(void){
+main(int argc, char **argv){
 	pasori* p;
 	felica* f;
-	int i;
-	int m;
-	uint8 b[16];
 	
-	p = pasori_open(NULL);
+	char* devpath = NULL;
+	if (argc == 2) {
+		devpath = argv[1];
+	}
+	p = pasori_open(devpath);
 	if(!p){
 		printf("error\n");
 		exit(-1);
