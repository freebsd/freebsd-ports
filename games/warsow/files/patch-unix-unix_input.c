--- unix/unix_input.c.orig	2009-06-07 12:34:29.000000000 +0300
+++ unix/unix_input.c	2009-12-20 20:48:33.000000000 +0200
@@ -27,6 +27,8 @@
 #include "x11_hardcoded.h"
 #endif
 
+#include "keysym2ucs.h"
+
 // TODO: add in_mouse?
 static cvar_t *in_dgamouse;
 
@@ -328,6 +330,7 @@
 		*key = -1; // can't handle it
 
 	// char events use the real layout
+	XKeysym keysym;
 	XLookupString( ev, buf, sizeof( buf ), NULL, 0 );
 
 	return buf;
@@ -339,7 +342,7 @@
 static char *XLateKey( XKeyEvent *ev, int *key )
 {
 	static char buf[64];
-	KeySym keysym;
+	KeySym keysym, origkeysym;
 	int XLookupRet;
 
 #ifdef PRINT_HARDCODING_TABLES
@@ -350,10 +353,14 @@
 		done = qtrue;
 	}
 #endif
-
 	*key = 0;
 
+	memset(buf, 0, 64);
 	XLookupRet = XLookupString( ev, buf, sizeof buf, &keysym, 0 );
+	origkeysym = keysym;
+	if (!XLookupRet)
+		keysym = XLookupKeysym(ev, 0); //Get default keysym for this key
+		
 #ifdef KBD_DBG
 	ri.Printf( "XLookupString ret: %d buf: %s keysym: %x\n", XLookupRet, buf, keysym );
 #endif
@@ -491,25 +498,43 @@
 	default:
 		if( XLookupRet == 0 )
 		{
-			/*
-			   if (com_developer->value)
-			   {
-			    ri.Printf(PRINT_ALL, "Warning: XLookupString failed on KeySym %d\n", keysym);
-			   }
-			 */
-			return NULL;
+
+			long ucs = keysym2ucs(origkeysym);
+			
+			if (ucs > 0) {
+			
+				//Put UCS data into buffer
+				buf[0] = ucs;
+				buf[1] = ucs >> 8;
+				buf[2] = ucs >> 16;
+				buf[3] = ucs >> 32;
+				buf[4] = 0;
+			
+			}
+			else {
+			
+				*key = 0;
+				return NULL;
+			
+			}
+			
+			*key = keysym2ucs(keysym); //Convert default keysym to a character
 		}
-		else
-		{
-			// XK_* tests failed, but XLookupString got a buffer, so let's try it
+		else {
+			
 			*key = *(unsigned char *)buf;
-			if( *key >= 'A' && *key <= 'Z' )
-				*key = *key - 'A' + 'a';
-			// if ctrl is pressed, the keys are not between 'A' and 'Z', for instance ctrl-z == 26 ^Z ^C etc.
-			// see https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=19
-			else if( *key >= 1 && *key <= 26 )
-				*key = *key + 'a' - 1;
+			
 		}
+		
+		// XK_* tests failed, but XLookupString got a buffer, so let's try it
+		
+		if( *key >= 'A' && *key <= 'Z' )
+			*key = *key - 'A' + 'a';
+		// if ctrl is pressed, the keys are not between 'A' and 'Z', for instance ctrl-z == 26 ^Z ^C etc.
+		// see https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=19
+		else if( *key >= 1 && *key <= 26 )
+			*key = *key + 'a' - 1;
+		
 		break;
 	}
 
@@ -580,7 +605,7 @@
 	qboolean dowarp = qfalse;
 	int mwx = x11display.win_width / 2;
 	int mwy = x11display.win_height / 2;
-	unsigned char *p;
+	qwchar *p;
 	int key = 0;
 	int time = 0;
 
@@ -620,7 +645,7 @@
 		{
 		case KeyPress:
 			time = Sys_XTimeToSysTime(event.xkey.time);
-			p = (unsigned char *)XLateKey( &event.xkey, &key );
+			p = (qwchar *)XLateKey( &event.xkey, &key );
 			if( key >= 0 && key <= 256 )
 				Key_Event( key, qtrue, time );
 			if( p )
