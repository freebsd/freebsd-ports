--- src/writecabrillo.c.orig	Sat Jul 10 22:23:15 2004
+++ src/writecabrillo.c	Sat Jul 10 22:24:47 2004
@@ -45,6 +45,7 @@
 	char buf[181];
 	char buffer[82]= "";
     char standardexchange[70] = "";
+    char ssa_mt_exchange[30];

 	FILE *fp1,  *fp2;

@@ -271,13 +272,12 @@
 					strcat(buffer, "599 ");

 				if (strcmp (whichcontest, "ssa_mt") == 0) {
+					int i=0, j=0, k = 0;
 //					strncat(buffer, buf+54, 9);  // tbf for all contests? RC
 					strcat(buffer, "                      ");

 					sprintf(buffer + 79, "%03d    ", atoi(buf+54));

-					char ssa_mt_exchange[30];
-					int i=0, j=0, k = 0;

 					for (i=0; i < 12; i++) {
 						if (isalpha(buf[54+i])){
