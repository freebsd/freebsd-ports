
$FreeBSD$

--- fbsd_kbd.c.orig
+++ fbsd_kbd.c
@@ -1,6 +1,8 @@
 #include <sys/fbio.h>
 #include <sys/kbio.h>
 #include <sys/consio.h>
+#include <sys/ioctl.h>
+#include <unistd.h>
 #include <vgl.h>
 
 #include "def.h"
@@ -20,6 +22,14 @@
 			 'a','s','d','f','g','h','j','k','l',';','\'','z','x',\
 			 'c','v','b','n','m',',','.','/',' '};
 
+#define	F1KEY	(59+128)
+#define	F10KEY	(68+128)
+#define	LALTKEY	(56+128)
+#define	RALTKEY	(93+128)
+#define	altpressed	(states[LALTKEY] || states[RALTKEY])
+
+extern bool started, pausef;
+
 void initkeyb(void)
 {
 	VGLKeyboardInit(VGL_CODEKEYS);
@@ -31,33 +41,80 @@
 	VGLKeyboardEnd();
 }
 
+bool UpdateStates(Sint4* result)
+{
+	Sint4 i;
+	bool isasymbol, state;
+	
+	if(*result < 128)
+		state = TRUE;
+	else {
+		state = FALSE;
+		*result -= 128;
+	}
+
+	isasymbol = FALSE;
+	for(i=0;quertycodes[i]!=0;i++)
+		if(*result == quertycodes[i]) {
+			*result = chars[i];
+			isasymbol = TRUE;
+			break;
+		}
+
+	if (isasymbol == FALSE)
+		*result+=128;
+
+	states[*result] = state;
+	return state;
+}
+
 void ProcessKbd(void)
 {
-	Sint4 result, i;
-	bool isasymbol;
+	Sint4 result;
+	static bool newconsf=FALSE;
 	bool state;
 
 	while((result = VGLKeyboardGetCh()) != 0) {
 
-		if(result < 128)
-			state = TRUE;
-		else {
-			state = FALSE;
-			result -= 128;
-		}
+		state=UpdateStates(&result);
 
-		isasymbol = FALSE;
-		for(i=0;quertycodes[i]!=0;i++)
-			if(result == quertycodes[i]) {
-				result = chars[i];
-				isasymbol = TRUE;
-				break;
+		if(newconsf==TRUE && pausef==TRUE) /* return to game ? */
+		  if(state==FALSE) 
+		    continue;
+		  else newconsf=FALSE;			/* yes */
+		
+		while(newconsf==FALSE && state==TRUE &&
+		      result>=F1KEY && result<=F10KEY && altpressed) {
+		    /* Alt-Fn pressed to switch consoles */
+		    int activecons=0;
+		    int newcons=result-F1KEY+1;
+		    ioctl(0, VT_GETACTIVE, &activecons);
+		    if(newcons==activecons) /* to another console ? */
+			break;
+		    
+		    newconsf=TRUE;
+		    /* do switch */
+		    ioctl(0,VT_ACTIVATE,(caddr_t)(long)newcons); 
+		    if(started==TRUE && pausef==FALSE) {
+			    pausef=TRUE;
+			    testpause(); /* force pause if game active */
+		    }
+		    else {
+		        VGLCheckSwitch(); /* game not active - just switch */
+		        /* now wait for another keyboard strike */
+			result=VGLKeyboardGetCh();
+			while(1) {
+			    if(result!=0) {
+				state=UpdateStates(&result);
+				    if(state==TRUE)     /* ignore releases */
+					break;	
+			        }
+		    	    usleep(500);	/* don't waste CPU when idle */
+			    result=VGLKeyboardGetCh();
 			}
-
-		if (isasymbol == FALSE)
-			result+=128;
-
-		states[result] = state;
+		    }
+		    newconsf=FALSE; /* switched back */
+		}
 
 		if(state == TRUE)
 			continue;
