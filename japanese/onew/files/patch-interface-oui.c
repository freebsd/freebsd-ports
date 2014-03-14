--- interface/oui.c.orig	1995-06-22 11:30:49.000000000 +0900
+++ interface/oui.c	2013-11-03 22:36:39.000000000 +0900
@@ -3,18 +3,34 @@
  ************************************************************************/
 
 #include <stdio.h>
+#include <stdarg.h>
 char *getenv();
 
+extern int ONEW_GETCHAR();
+extern int ONEW_PEEKCHAR();
+extern int ONEW_GOT_2BCHAR();
+extern int ONEW_DISP_ROMKANMODE();
+extern int ONEW_DISP_KANAHALVES();
+extern int ONEW_KANAKAN();
+extern int ONEW_DISP_KANAKANB();
+extern int ONEW_KAKUTEI();
+extern int ONEW_BEEP();
+extern int ONEW_MESSAGE();
+extern int ONEW_MESSAGE_COLS();
+
 static FILE *ouiFp;
 static int uin;
 static int uilev;
-ouiTrace(prim,fmt,a,b,c,d,e,f,g)
-	char *fmt;
-	FILE *prim;
-{	char *logf;
+void
+ouiTrace(char *prim, char *fmt, ...)
+{
+	va_list list;
+	char *logf;
 
+	va_start(list, fmt);
 	if( ouiFp == NULL ){
-		if( logf = getenv("ONEW_UIFLOG") )
+		logf = getenv("ONEW_UIFLOG");
+		if( logf )
 			ouiFp = fopen(logf,"w");
 		if( ouiFp == NULL )
 			ouiFp = (FILE*)-1;
@@ -23,11 +39,15 @@
 		return;
 	fprintf(ouiFp,"%4d ",++uin);
 	fprintf(ouiFp,"%-16s ",prim);
-	if(fmt) fprintf(ouiFp,fmt,a,b,c,d,e,f,g);
+
+	if(fmt) vfprintf(ouiFp,fmt,list);
 	fprintf(ouiFp,"\n");
+	va_end(list);
 }
-Onew_ouiTrace(prim,fmt,a,b,c,d,e,f,g){ ouiTrace(prim,fmt,a,b,c,d,e,f,g); }
+void
+Onew_ouiTrace(char *prim, char *fmt, va_list ap) { ouiTrace(prim, fmt, ap); }
 
+int
 ouiGETCHAR()
 {	int ch;
 
@@ -37,6 +57,7 @@
 	/*if( ch == '\n' ) LASTMSG[0] = 0;*/
 	return ch;
 }
+int
 ouiPEEKCHAR(msecp)
 	int *msecp;
 {	int ch;
@@ -47,35 +68,41 @@
 		ouiTrace("PEEKCHAR","(%x)",ch);
 	return ch;
 }
+int
 ouiGOT_2BCHAR(buf,hi,lo)
 	char *buf;
 {
 	ouiTrace("GOT_2BCHAR",0);
 	return ONEW_GOT_2BCHAR(buf,hi,lo);
 }
+int
 ouiDISP_ROMKANMODE(mode,help,modeflags)
 	char *mode,*help;
 {
 	ouiTrace("DISP_ROMKANMODE","%-6s[%04x]",mode,modeflags);
 	return ONEW_DISP_ROMKANMODE(mode,help,modeflags);
 }
+int
 ouiDISP_KANAHALVES(str)
 	char *str;
 {
 	ouiTrace("DISP_KANAHALVES","(%s)",str);
 	return ONEW_DISP_KANAHALVES(str);
 }
+int
 ouiKANAKAN(kkchar)
 {
 	ouiTrace("KANAKAN","%x",kkchar);
 	return ONEW_KANAKAN(kkchar);
 }
+int
 ouiDISP_KANAKANB(so,left,cur,right)
 	char *left,*cur,*right;
 {
 	ouiTrace("DISP_KANAKANB","%d",so);
 	return ONEW_DISP_KANAKANB(so,left,cur,right);
 }
+int
 ouiKAKUTEI(kakutei_start_char)
 {
 	ouiTrace("KAKUTEI","%x",kakutei_start_char);
@@ -85,11 +112,13 @@
  *	ONEW_KAKUTEI: returns true if the character is consumed for kakutei
  */
 
+int
 ouiBEEP(waitsec)
 {
 	ouiTrace("BEEP",0);
 	return ONEW_BEEP(waitsec);
 }
+int
 ouiMESSAGE_COLS()
 {	int cols;
 
@@ -97,29 +126,36 @@
 	ouiTrace("MESSAGE_COLS","%d",cols);
 	return cols;
 }
-ouiMESSAGE(so,fmt,a,b,c,d,e,f,g)
-	char *fmt;
-	char *a,*b,*c,*d,*e,*f,*g;
+int
+ouiMESSAGE(int so, char *fmt, ...)
 {	char msg[512];
+	va_list list;
+	int ret;
 
-	sprintf(msg,fmt,a,b,c,d,e,f,g);
+	va_start(list, fmt);
+	sprintf(msg,fmt,list);
 	ouiTrace("MESSAGE","<%s>",msg);
-	return ONEW_MESSAGE(so,fmt,a,b,c,d,e,f,g);
+	ret = ONEW_MESSAGE(so, fmt, list);
+	va_end(list);
+	
+	return (ret);
 }
 
 
 /*
  *
  */
-Onew_disp_kanahalf(ch)
+void Onew_disp_kanahalves(char *);
+void
+Onew_disp_kanahalf(int ch)
 {	char buf[128];
 
 	buf[0] = ch;
 	buf[1] = 0;
 	Onew_disp_kanahalves(buf);
 }
-Onew_disp_kanahalves(str)
-	char *str;
+void
+Onew_disp_kanahalves(char *str)
 {
 	if( *str == 0 )
 		ouiDISP_KANAHALVES(" ");
