--- kc12x24.c.orig	Sun Dec 17 01:20:19 1995
+++ kc12x24.c	Sun Apr 30 10:43:54 2000
@@ -10,12 +10,12 @@
 char bdfhead[]=
 "STARTFONT 2.1\n"
 "COMMENT X\n"
-"FONT kc12x24\n"
+"FONT -kc-fixed-medium-r-normal--24-170-100-100--c-120-iso8859-1\n"
 "SIZE 24 100 100\n"
 "FONTBOUNDINGBOX 12 24 0 -2\n"
 "STARTPROPERTIES 19\n"
 "FONTNAME_REGISTRY \"\"\n"
-"FOUNDRY \"Kau Chauo\"\n"
+"FOUNDRY \"KC\"\n"
 "FAMILY_NAME \"Fixed\"\n"
 "WEIGHT_NAME \"Medium\"\n"
 "SLANT \"R\"\n"
@@ -36,7 +36,7 @@
 "ENDPROPERTIES\n"
 "CHARS 256\n";
 
-void main( void )
+int main( void )
 {
 	FILE *fr,*fw;
 	int i,j;
@@ -68,4 +68,5 @@
 	}
 	
 	fprintf(fw, "ENDFONT\n");
+    return 0;
 }
--- kc15f.c.orig	Wed Jan 19 02:14:40 2000
+++ kc15f.c	Wed Jan 19 03:05:11 2000
@@ -12,26 +12,33 @@
 char head[]=
 "STARTFONT 2.1\n"
 "COMMENT 16x15 Font\n"
-"FONT kc15f\n"
+"FONT -kc-fixed-medium-r-normal--16-160-72-72-c-160-big5-0\n"
 "SIZE 16 100 100\n"
 "FONTBOUNDINGBOX 16 15 0 -1\n"
-"STARTPROPERTIES 12\n"
+"STARTPROPERTIES 19\n"
 "FONT_ASCENT 14\n"
 "FONT_DESCENT 1\n"
 "DEFAULT_CHAR 41280\n"
-"COPYRIGHT \"KC\"\n"
-"POINT_SIZE 240\n"
-"FONT \"kc15f\"\n"
-"WEIGHT 10\n"
-"RESOLUTION 103\n"
-"RESOLUTION_X 100\n"
-"RESOLUTION_Y 100\n"
-"X_HEIGHT 4294967295\n"
-"QUAD_WIDTH 16\n"
+"COPYRIGHT \"Kau Chauo Business CO.\"\n"
+"FONTNAME_REGISTRY \"\"\n"
+"FOUNDRY \"KC\"\n"
+"FAMILY_NAME \"Fixed\"\n"
+"WEIGHT_NAME \"Medium\"\n"
+"SLANT \"R\"\n"
+"SETWIDTH_NAME \"Normal\"\n"
+"ADD_STYLE_NAME \"\"\n"
+"PIXEL_SIZE 16\n"
+"POINT_SIZE 160\n"
+"RESOLUTION_X 72\n"
+"RESOLUTION_Y 72\n"
+"SPACING \"C\"\n"
+"AVERAGE_WIDTH 160\n"
+"CHARSET_REGISTRY \"BIG5\"\n"
+"CHARSET_ENCODING \"0\"\n"
 "ENDPROPERTIES\n"
 "CHARS 13867\n";
 
-FILE *fp,*fr1, *fr2, *fw=stdout;
+FILE *fp,*fr1, *fr2;
 
 int count, ofs;
 
@@ -42,21 +49,21 @@
 	int v,i;
 
 	if ((v=fread(bf,1,sizeof(bf),fp)) != sizeof(bf)) return; 
-	fprintf(fw,"STARTCHAR %d\n", count);
+	fprintf(stdout,"STARTCHAR %d\n", count);
 	tt[0]=ofs>>8;
 	tt[1]=ofs&255;
 	ser_b5(tt,uu);
-	fprintf(fw,"ENCODING %d\n", (u_short)uu[0]<<8 | uu[1]);
-	fprintf(fw,"SWIDTH 640 0\n");
-	fprintf(fw,"DWIDTH 16 0\n");
-	fprintf(fw,"BBX 16 15 0 -1\n");
-	fprintf(fw,"BITMAP\n");
+	fprintf(stdout,"ENCODING %d\n", (u_short)uu[0]<<8 | uu[1]);
+	fprintf(stdout,"SWIDTH 640 0\n");
+	fprintf(stdout,"DWIDTH 16 0\n");
+	fprintf(stdout,"BBX 16 15 0 -1\n");
+	fprintf(stdout,"BITMAP\n");
 	
 	for(i=0;i<15;i++) {
 		v=((u_int)bf[i][0]<<8) | bf[i][1];
-		fprintf(fw,"%04x\n", v);
+		fprintf(stdout,"%04x\n", v);
 	}
-	fprintf(fw,"ENDCHAR\n");
+	fprintf(stdout,"ENDCHAR\n");
 }
 
 main()
@@ -65,7 +72,7 @@
 	if ((fp=fopen("spcfont.15","r"))==NULL) {
 		fprintf(stderr,"kc15 Error01:Can't open spcfont.15\n"); exit(2); 
 	}
-	fputs(head,fw);
+	fputs(head,stdout);
 
 	ofs=0x8400;
 	while (!feof(fp)) {
@@ -102,8 +109,7 @@
 	fclose(fr1);
 	fclose(fr2);
 
-	fprintf(fw,"ENDFONT\n");
+	fprintf(stdout,"ENDFONT\n");
 
 	fclose(fp);
-	fclose(fw);
 }
--- kc24f.c.orig	Wed Jan 19 02:14:44 2000
+++ kc24f.c	Wed Jan 19 02:48:46 2000
@@ -11,26 +11,33 @@
 char head[]=
 "STARTFONT 2.1\n"
 "COMMENT 24x24 Font\n"
-"FONT kc24f\n" 
+"FONT -kc-fixed-medium-r-normal--24-240-100-100-c-240-big5-0\n" 
 "SIZE 24 100 100\n"
 "FONTBOUNDINGBOX 24 24 0 -2\n"
-"STARTPROPERTIES 12\n"
+"STARTPROPERTIES 19\n"
 "FONT_ASCENT 22\n"
 "FONT_DESCENT 2\n"
 "DEFAULT_CHAR 41280\n"
-"COPYRIGHT \"KC\"\n"
+"COPYRIGHT \"Kau Chauo Business CO.\"\n"
+"FONTNAME_REGISTRY \"\"\n"
+"FOUNDRY \"KC\"\n"
+"FAMILY_NAME \"Fixed\"\n"
+"WEIGHT_NAME \"Medium\"\n"
+"SLANT \"R\"\n"
+"SETWIDTH_NAME \"Normal\"\n"
+"ADD_STYLE_NAME \"\"\n"
+"PIXEL_SIZE 24\n"
 "POINT_SIZE 240\n"
-"FONT \"kc24f\"\n"
-"WEIGHT 10\n"
-"RESOLUTION 103\n"
 "RESOLUTION_X 100\n"
 "RESOLUTION_Y 100\n"
-"X_HEIGHT 4294967295\n"
-"QUAD_WIDTH 24\n"
+"SPACING \"C\"\n"
+"AVERAGE_WIDTH 240\n"
+"CHARSET_REGISTRY \"BIG5\"\n"
+"CHARSET_ENCODING \"0\"\n"
 "ENDPROPERTIES\n"
 "CHARS 13867\n";
 
-FILE *fp,*fr1, *fr2, *fw=stdout;
+FILE *fp,*fr1, *fr2;
 
 int count, ofs;
 
@@ -42,21 +49,21 @@
 
 
 if ((v=fread(bf,1,72,fp)) != 72) return; 
-fprintf(fw,"STARTCHAR %d\n", count);
+fprintf(stdout,"STARTCHAR %d\n", count);
 tt[0]=ofs>>8;
 tt[1]=ofs&255;
 ser_b5(tt,uu);
-fprintf(fw,"ENCODING %d\n", (u_short)uu[0]<<8 | uu[1]);
-fprintf(fw,"SWIDTH 960 0\n");
-fprintf(fw,"DWIDTH 24 0\n");
-fprintf(fw,"BBX 24 24 0 -2\n");
-fprintf(fw,"BITMAP\n");
+fprintf(stdout,"ENCODING %d\n", (u_short)uu[0]<<8 | uu[1]);
+fprintf(stdout,"SWIDTH 960 0\n");
+fprintf(stdout,"DWIDTH 24 0\n");
+fprintf(stdout,"BBX 24 24 0 -2\n");
+fprintf(stdout,"BITMAP\n");
 zc=0;
 for(i=0;i<24;i++) {
 	v=(((u_int)bf[i][0]<<16) | ((u_int)bf[i][1]<<8)) | bf[i][2];
-	fprintf(fw,"%06x\n", v);
+	fprintf(stdout,"%06x\n", v);
 }
-fprintf(fw,"ENDCHAR\n");
+fprintf(stdout,"ENDCHAR\n");
 }
 
 main()
@@ -65,7 +72,7 @@
 if ((fp=fopen("spcfont.24","r"))==NULL) {
   fprintf(stderr,"kc24 Error 1:Can't open spcfont.24\n"); exit(2); 
 }
-fputs(head,fw);
+fputs(head,stdout);
 
 ofs=0x8400;
 while (!feof(fp)) {
@@ -101,8 +108,7 @@
 fclose(fr1);
 fclose(fr2);
 
-fprintf(fw,"ENDFONT\n");
+fprintf(stdout,"ENDFONT\n");
 
 fclose(fp);
-fclose(fw);
 }
--- kc8x15.c.orig	Sun Dec 17 01:19:08 1995
+++ kc8x15.c	Sun Apr 30 10:45:07 2000
@@ -10,12 +10,12 @@
 char bdfhead[]=
 "STARTFONT 2.1\n"
 "COMMENT X\n"
-"FONT kc8x15\n"
+"FONT -kc-fixed-medium-r-normal--15-170-100-100-c-80-iso8859-1\n"
 "SIZE 15 100 100\n"
 "FONTBOUNDINGBOX 8 15 0 -1\n"
 "STARTPROPERTIES 19\n"
 "FONTNAME_REGISTRY \"\"\n"
-"FOUNDRY \"Kau Chauo\"\n"
+"FOUNDRY \"KC\"\n"
 "FAMILY_NAME \"Fixed\"\n"
 "WEIGHT_NAME \"Medium\"\n"
 "SLANT \"R\"\n"
@@ -37,7 +37,7 @@
 "CHARS 256\n";
 
 
-void main( void )
+int main( void )
 {
 	FILE *fr,*fw;
 	int i,j;
@@ -69,4 +69,5 @@
 	}
 
 	fprintf(fw, "ENDFONT\n");
+	return 0;
 }
