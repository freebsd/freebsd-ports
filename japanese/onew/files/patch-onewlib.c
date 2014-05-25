--- onewlib.c.orig	1995-07-02 16:55:41.000000000 +0900
+++ onewlib.c	2014-05-25 11:55:49.000000000 +0900
@@ -50,6 +50,11 @@
 int ONEW_I_SYNC_CHAR	= 0xFF;
 int ONEW_KK_OPDICT	= 'x';
 
+static definedKanamode();
+static romkan_modesw();
+static thru_char1();
+static Onew_kakuteiInRomkan();
+
 #define MODE_SWITCHER	ONEW_MODE_SWITCHER
 #define ZENKAKU_TOGGLE	ONEW_ZENKAKU_TOGGLE
 #define KANA_TOGGLE	ONEW_KANA_TOGGLE
@@ -116,9 +121,6 @@
 }
 ONEW_getch1(){
    int ch;
-   static definedKanamode();
-   static romkan_modesw();
-   static thru_char1();
 
    for(;;){
 	ch = ONEW_getch0(ONEW_getch_asis);
@@ -313,7 +315,6 @@
 
 kget_char1(){
 	unsigned int kc;
-   	static Onew_kakuteiInRomkan();
 
 	if( !Onew_RK_init() ){
 		kc = OnewGetchar();
