
$FreeBSD$

--- source/oldlzw.cpp	2001/02/17 15:08:39	1.1
+++ source/oldlzw.cpp	2001/02/17 15:08:54
@@ -342,7 +339,7 @@
             DecodeBuffer = (unsigned char *) realloc ( DecodeBuffer, DecodeBufferSize + 1000 );
 
             if ( ! DecodeBuffer )
-                throw toutofmem ( DecodeBufferSize + 1000 );
+                goto except1;
             else      
                 DecodeBufferSize += 1000;
         }
@@ -350,6 +347,9 @@
     }
     DecodeBuffer[ count++ ] = code;
     return ( count );
+
+except1:
+    throw toutofmem ( DecodeBufferSize + 1000 );
 }
 
 
@@ -464,7 +464,7 @@
                   count = LZWLoadBuffer ( 0, incode );
       
               if ( count == 0 )
-                 throw ASCexception();
+                 goto except1;
                              
               inchar = DecodeBuffer[ count - 1 ];
               while ( count )
@@ -492,7 +492,10 @@
       return pos;
    }
 
-   // return 0;
+   return 0;
+
+except1:
+   throw ASCexception();
 }
 
 
