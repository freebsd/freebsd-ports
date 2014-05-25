--- dialogue/onewdic.c.orig	2014-05-25 11:35:24.000000000 +0900
+++ dialogue/onewdic.c	2014-05-25 11:39:56.000000000 +0900
@@ -18,6 +18,8 @@
 History:
 	940127	created
 ///////////////////////////////////////////////////////////////////////*/
+#include <stdlib.h>
+#include <string.h>
 #include "onew.h"
 int ONEW_MAXWORDS = 32;
 
@@ -32,6 +34,7 @@
 
 char *strpbrk();
 
+int
 Onew_addword(dic,word)
 	char *dic;
 	char *word;
@@ -40,14 +43,14 @@
 	int len;
 
 	if( ONEW_MAXWORDS <= 0 )
-		return;
+		return 0;
 
 	if( *word == 0 )
-		return;
+		return 0;
 
-	if( np = strpbrk(word,"\n\r") ){
+	if((np = strpbrk(word,"\n\r")) != NULL){
 		if( np == word )
-			return;
+			return 0;
 		len = np - word;
 	}else	len = strlen(word);
 
@@ -97,13 +100,13 @@
 	return wp;
 }
 /* this function does not perform proper sorting  X-< */
-static word_sort(nth,inc)
+static int word_sort(nth,inc)
 {	Word *dwp,*pwp,*twp;
 	Word **dwpp,**pwpp;
 	int nnth;
 
 	if( (dwp = nth_wp(nth,&dwpp)) == 0 )
-		return;
+		return 0;
 	dwp->w_freq += inc;
 
 	pwpp = &word_list;
@@ -116,7 +119,7 @@
 		nnth++;
 	}
 	if( pwp == 0 || pwp == dwp )
-		return;
+		return 0;
 
 	twp = *pwpp;
 	*pwpp = dwp;
@@ -143,14 +146,15 @@
 		return str;
 	}else	return 0;
 }
-static word_label(label,from,to,max)
+static void word_label(label,from,to,max)
 	char *label;
 {
 	sprintf(label,"[%d/%d]",to-1,max);
 }
-static word_error(){
+static void word_error(){
 }
 
+void
 Onew_getword(key)
 	char *key;
 {	int n;
@@ -178,11 +182,11 @@
 }
 
 
-static
+static int
 ONEWkanakan_ready(){
 	return 1;
 }
-static
+static void
 ONEWkanakan_freqsave()
 {
 }
@@ -192,29 +196,31 @@
 {
 	strncpy(kouho,nth_str(i),size);
 }
-static
+static void
 ONEWkanakan()
 {
 }
-static
+static void
 ONEWbunsetu_next()
 {
 }
-static
+static void
 ONEWbunsetu_expand()
 {
 }
-static
+static void
 ONEWbunsetu_shrink()
 {
 }
-static
+static void
 ONEWjisyo_touroku()
 {
 }
-static
+static void
 ONEWjisyo_hinshi()
 {
 }
+#if 0
 RegisterKanakan(ONEW_OnewKanakan);
+#endif
 
