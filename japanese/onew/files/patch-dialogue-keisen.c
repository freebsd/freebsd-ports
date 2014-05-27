--- dialogue/keisen.c.orig	2014-05-25 11:41:08.000000000 +0900
+++ dialogue/keisen.c	2014-05-25 11:45:53.000000000 +0900
@@ -6,7 +6,7 @@
 int KEISEN_TOGGLE_A	= Cntl('N');
 int KEISEN_TOGGLE_B	= Cntl('B');
 
-static
+static int
 keisen_toggle(type)
 int  type;
 {
@@ -39,7 +39,8 @@
 	}
 	return 0;
 }
-keisen_init(){
+void
+keisen_init(void){
 	ONEW_KEISEN_ON = getenv("ONEW_KEISENMODE");
 	if( ONEW_KEISEN_ON == 0 )
 		return;
