
$FreeBSD$

--- source/basegfx.cpp	2001/02/17 13:59:07	1.1
+++ source/basegfx.cpp	2001/02/17 14:00:16
@@ -409,7 +406,7 @@
       wp[1] = hd->y / 2;
 
       if ( ( wp[0] + 1 ) * ( wp[1] + 1 ) + 4 >= xlatbuffersize )
-         throw fatalgraphicserror ( "halfpict : picture larger than buffer ! " );
+         goto except;
 
       dest += 4;
 
@@ -449,7 +446,7 @@
             }
          }
          if ( (int)dest - (int)xlatbuffer > xlatbuffersize )
-            throw fatalgraphicserror ( "halfpict : picture larger than buffer ! " );
+             goto except;
 
       }
    } else {
@@ -462,7 +459,7 @@
       wp[1] = wp2[1] / 2;
 
       if ( ( wp[0] + 1 ) * ( wp[1] + 1 ) + 4 >= xlatbuffersize )
-         throw fatalgraphicserror ( "halfpict : picture larger than buffer ! " );
+         goto except;
 
       dest += 4;
       buf += 4;
@@ -482,6 +479,9 @@
 
    }
    return xlatbuffer;
+
+except:
+   throw fatalgraphicserror ( "halfpict : picture larger than buffer ! " );
 } 
 
 
