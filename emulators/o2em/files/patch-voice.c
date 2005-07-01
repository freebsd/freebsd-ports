--- ../o2em117src.old/src/voice.c	Sat Jun 25 12:47:22 2005
+++ src/voice.c	Sat Jun 25 12:47:27 2005
@@ -21,6 +21,7 @@
 #include "voice.h"
 #include "allegro.h"
 
+#define MAXC 1024
 
 static SAMPLE *voices[9][128];
 static int voice_bank=0;
@@ -33,7 +34,7 @@
 
 void load_voice_samples(void){
 	int bank, sam, i, ld=0;
-	char name[40];
+	char name[MAXC];
 	SAMPLE *sp=NULL;
 
 	printf("Loading voice samples...  ");
@@ -47,12 +48,12 @@
 			else
 				bank = 0xE4;
 
-			sprintf(name,"voice/%02x%02x.wav",bank,sam+0x80);
+			sprintf(name,"%s/o2em/voice/%02x%02x.wav",PREFIX,bank,sam+0x80);
 
 			voices[i][sam] = load_sample(name);
 
 			if (!voices[i][sam]) {
-				sprintf(name,"voice/%02X%02X.WAV",bank,sam+0x80);
+				sprintf(name,"%s/o2em/voice/%02X%02X.WAV",PREFIX,bank,sam+0x80);
 				voices[i][sam] = load_sample(name);
 			}
 
