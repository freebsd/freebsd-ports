--- gbchar.c.orig	1992-08-23 11:37:58.000000000 +0800
+++ gbchar.c	2013-09-26 20:54:32.000000000 +0800
@@ -26,6 +26,7 @@ int	commandcounter=0;
 int	rotate_flag=FALSE;
 int	setgray=0;
 
+void
 ASCshow() {
 	if (ascflag) {
 		if (!Analyse_flag) fprintf(out,") S\n");
@@ -33,6 +34,7 @@ ASCshow() {
 	}
 }
 
+void
 newline ()
 {
 	charcount=0;  H=_LM; 
@@ -82,6 +84,7 @@ newline ()
 	}
 }
 
+void
 put_ASC(c)
 int c;
 {
@@ -126,6 +129,7 @@ int c;
 		newline ();
 }
 
+void
 put_CH(ch1,ch2)
 int ch1,ch2;
 {
@@ -217,6 +221,7 @@ int ch1,ch2;
       return ch2;
 }
 
+void
 putString(st)
 char* st;
 {
@@ -238,6 +243,7 @@ char* st;
 
 /*===========================================================================*/
 
+void
 DefCHdict() {
 	long i,j,k=0;
 	char st1[10];
@@ -249,7 +255,7 @@ DefCHdict() {
 		if (CHcode[i][j]>=CHAR_LIMIT) k++;
 	   }
 
-	fprintf(out,"/CHdict %d dict def\nCHdict begin\n",k+400);
+	fprintf(out,"/CHdict %ld dict def\nCHdict begin\n",k+400);
 
 	for (i=0;i<94*94;i++) 
 	   for (j=0;j<6;j++) {
@@ -257,7 +263,7 @@ DefCHdict() {
 			fseek(CHFONT[j].fp,offset_CH+i*size_of_CH,0);
 			fgets(line,size_of_CH,CHFONT[j].fp); 
 			sscanf(line,"%s %s",st1,st2);
-			fprintf(out,"/C%1d%s {H {<%s>} I G} def \n",j,st1,st2);
+			fprintf(out,"/C%1ld%s {H {<%s>} I G} def \n",j,st1,st2);
 		}
 	   }
 }
@@ -265,7 +271,8 @@ DefCHdict() {
 
 /*AnalyseDoc: analyse the input document.*/
 
-int AnalyseDoc() {
+void
+AnalyseDoc() {
   int	ch=0,ch1,ch2,i,j;
 
   for (i=0;i<94*94;i++) 
@@ -326,13 +333,14 @@ int readchar() {
 			c=fgetc(in);
 	}
 
-	if (CH_mode)
-		if (((c&0x7f)>=0x21)&&((c&0x7f)<=0x7e))
+	if (CH_mode) {
+		if (((c&0x7f)>=0x21)&&((c&0x7f)<=0x7e)) {
 			return c|0x80;
-		else {
+        } else {
 			CH_mode=FALSE;
 			return c;
 		}
+    }
 			
 	if (!format_flag) return c;
 
