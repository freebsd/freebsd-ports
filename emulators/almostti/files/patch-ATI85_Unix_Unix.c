--- ATI85/Unix/Unix.c.orig	2009-12-17 08:32:38 UTC
+++ ATI85/Unix/Unix.c
@@ -228,11 +228,19 @@ int ShowBackdrop(const char *FileName)
       printf("error: %d\n", decoder.error);
       return(0);
   }
+#ifndef PORTRAIT
   if (decoder.infoPng.width != WIDTH) {
+#else
+  if (decoder.infoPng.height != WIDTH) {
+#endif
       printf("error: skin width != %d\n", WIDTH);
       return(0);
   }
+#ifndef PORTRAIT
   if (decoder.infoPng.height != HEIGHT) {
+#else
+  if (decoder.infoPng.width != HEIGHT) {
+#endif
       printf("error: skin height != %d\n", HEIGHT);
       return(0);
   }
@@ -242,10 +250,20 @@ int ShowBackdrop(const char *FileName)
   pixel *P = (pixel *)OutImage.Data;
   unsigned char *Q = image;
     
+#ifndef PORTRAIT
   for (j = HEIGHT * WIDTH; j; j--) {
       *P++ = X11GetColor(*Q++,*Q++,*Q++);
       Q++;
   }
+#else
+  uint k;
+  for (k = 0; k < HEIGHT; k++) {
+    for (j = WIDTH; j > 0; j--) {
+      Q = image + (j * HEIGHT + k) * 4;
+     *P++ = X11GetColor(*Q++,*Q++,*Q++);
+    }
+  }
+#endif
 
   // Cleanup decoder
   free(image);
@@ -291,11 +309,25 @@ void HandleKeys(unsigned int Key)
       case XK_Up:        KBD_RES(KBD_UP);KeyReady=1;break;
       case XK_Down:      KBD_RES(KBD_DOWN);KeyReady=1;break;
       case XK_greater:   KBD_RES(KBD_STO);KeyReady=1;break;
-      case XK_Delete:
-      case XK_BackSpace: KBD_RES(KBD_DEL);KeyReady=1;break;
-      case XK_Home:      KBD_RES(KBD_CLEAR);KeyReady=1;break;
+      case XK_Delete:    KBD_RES(KBD_DEL);KeyReady=1;break;
+      case XK_BackSpace: KBD_RES(KBD_CLEAR);KeyReady=1;break;
       case XK_Alt_L:
       case XK_Alt_R:     KBD_RES(KBD_ALPHA);KeyReady=1;break;
+      case XK_KP_Home:   KBD_RES(KBD_7);KeyReady=1;break;
+      case XK_KP_Up:     KBD_RES(KBD_8);KeyReady=1;break;
+      case XK_KP_Page_Up: KBD_RES(KBD_9);KeyReady=1;break;
+      case XK_KP_Left:   KBD_RES(KBD_4);KeyReady=1;break;
+      case XK_KP_Begin:  KBD_RES(KBD_5);KeyReady=1;break;
+      case XK_KP_Right:  KBD_RES(KBD_6);KeyReady=1;break;
+      case XK_KP_End:    KBD_RES(KBD_1);KeyReady=1;break;
+      case XK_KP_Down:   KBD_RES(KBD_2);KeyReady=1;break;
+      case XK_KP_Page_Down: KBD_RES(KBD_3);KeyReady=1;break;
+      case XK_KP_Insert: KBD_RES(KBD_0);KeyReady=1;break;
+      case XK_KP_Delete: KBD_RES(KBD_DOT);KeyReady=1;break;
+      case XK_KP_Divide: KBD_RES(KBD_DIV);KeyReady=1;break;
+      case XK_KP_Multiply: KBD_RES(KBD_MUL);KeyReady=1;break;
+      case XK_KP_Subtract: KBD_RES(KBD_MINUS);KeyReady=1;break;
+      case XK_KP_Add:    KBD_RES(KBD_PLUS);KeyReady=1;break;
       default:
         Key&=CON_KEYCODE;
         if((Key>=' ')&&(Key<0x80)) { KBD_RES(Key);KeyReady=1; }
@@ -343,11 +375,25 @@ void HandleKeys(unsigned int Key)
       case XK_Up:        KBD_SET(KBD_UP);KeyReady=1;break;
       case XK_Down:      KBD_SET(KBD_DOWN);KeyReady=1;break;
       case XK_greater:   KBD_SET(KBD_STO);KeyReady=1;break;
-      case XK_Delete:
-      case XK_BackSpace: KBD_SET(KBD_DEL);KeyReady=1;break;
-      case XK_Home:      KBD_SET(KBD_CLEAR);KeyReady=1;break;
+      case XK_Delete:    KBD_SET(KBD_DEL);KeyReady=1;break;
+      case XK_BackSpace: KBD_SET(KBD_CLEAR);KeyReady=1;break;
       case XK_Alt_L:
       case XK_Alt_R:     KBD_SET(KBD_ALPHA);KeyReady=1;break;
+      case XK_KP_Home:   KBD_SET(KBD_7);KeyReady=1;break;
+      case XK_KP_Up:     KBD_SET(KBD_8);KeyReady=1;break;
+      case XK_KP_Page_Up: KBD_SET(KBD_9);KeyReady=1;break;
+      case XK_KP_Left:   KBD_SET(KBD_4);KeyReady=1;break;
+      case XK_KP_Begin:  KBD_SET(KBD_5);KeyReady=1;break;
+      case XK_KP_Right:  KBD_SET(KBD_6);KeyReady=1;break;
+      case XK_KP_End:    KBD_SET(KBD_1);KeyReady=1;break;
+      case XK_KP_Down:   KBD_SET(KBD_2);KeyReady=1;break;
+      case XK_KP_Page_Down: KBD_SET(KBD_3);KeyReady=1;break;
+      case XK_KP_Insert: KBD_SET(KBD_0);KeyReady=1;break;
+      case XK_KP_Delete: KBD_SET(KBD_DOT);KeyReady=1;break;
+      case XK_KP_Divide: KBD_SET(KBD_DIV);KeyReady=1;break;
+      case XK_KP_Multiply: KBD_SET(KBD_MUL);KeyReady=1;break;
+      case XK_KP_Subtract: KBD_SET(KBD_MINUS);KeyReady=1;break;
+      case XK_KP_Add:    KBD_SET(KBD_PLUS);KeyReady=1;break;
       default:
         Key&=CON_KEYCODE;
         if((Key>=' ')&&(Key<0x80)) { KBD_SET(Key);KeyReady=1; }
