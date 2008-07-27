--- lib/colorsel.cc.orig	2008-07-27 18:51:10.000000000 +0200
+++ lib/colorsel.cc	2008-07-27 18:52:25.000000000 +0200
@@ -210,9 +210,9 @@
 		 * SS: some non-portable code changed.
 		 */
                 if( selType == csBackground )
-                    color = (int)event.message.infoPtr >> 4;
+                    color = (intptr_t)event.message.infoPtr >> 4;
                 else
-                    color = (int)event.message.infoPtr & 0x0F;
+                    color = (intptr_t)event.message.infoPtr & 0x0F;
                 drawView();
                 return ;
                 }
@@ -278,7 +278,7 @@
 	/*
 	 * SS: some non-portable code changed.
 	 */
-        value = (int)event.message.infoPtr;
+        value = (intptr_t)event.message.infoPtr;
         drawView();
         }
 }
@@ -357,12 +357,12 @@
 		/*
 		 * SS: some non-portable code changed.
 		 */
-                *color = (*color & 0x0F) | (((int)event.message.infoPtr << 4) & 0xF0);
+                *color = (*color & 0x0F) | (((intptr_t)event.message.infoPtr << 4) & 0xF0);
                 drawView();
                 break;
 
             case cmColorForegroundChanged:
-                *color = (*color & 0xF0) | ((int)event.message.infoPtr & 0x0F);
+                *color = (*color & 0xF0) | ((intptr_t)event.message.infoPtr & 0x0F);
                 drawView();
             }
 }
@@ -507,7 +507,7 @@
 	/*
 	 * SS: some non-portable code changed.
 	 */
-        setGroupIndex(focused, (int)ev.message.infoPtr);
+        setGroupIndex(focused, (intptr_t)ev.message.infoPtr);
 }
 
 void TColorGroupList::setGroupIndex(uchar groupNum, uchar itemNum)
@@ -810,7 +810,7 @@
 	/*
 	 * SS: some non-portable code changed.
 	 */
-        display->setColor( (uchar *)&pal->data[(int)event.message.infoPtr] );
+        display->setColor( (uchar *)&pal->data[(intptr_t)event.message.infoPtr] );
 }
 
 ushort TColorDialog::dataSize()
