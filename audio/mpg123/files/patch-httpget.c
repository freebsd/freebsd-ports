--- httpget.c.orig	2003-11-13 18:34:37.000000000 +0000
+++ httpget.c	2003-11-13 18:35:10.000000000 +0000
@@ -55,11 +55,10 @@ void readstring (char *string, int maxle
 #endif
 	int pos = 0;
 
-	while(1) {
+	while(pos < maxlen) {
 		if( read(fileno(f),string+pos,1) == 1) {
 			pos++;
 			if(string[pos-1] == '\n') {
-				string[pos] = 0;
 				break;
 			}
 		}
@@ -68,6 +67,7 @@ void readstring (char *string, int maxle
 			exit(1);
 		}
 	}
+	string[pos] = 0;
 #if 0
 	do {
 		result = fgets(string, maxlen, f);
