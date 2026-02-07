src/Base64Encoder.cpp:170:25: error: cast from pointer to smaller type 'char' loses information
      retval[outlength]=(char) NULL;
                        ^~~~~~~~~~~

--- src/Base64Encoder.cpp.orig	2018-08-26 19:38:04 UTC
+++ src/Base64Encoder.cpp
@@ -167,7 +167,7 @@ char * Base64Encoder::encode(const char *data, int dat
                   linelength=0;
             }
       };
-      retval[outlength]=(char) NULL;
+      retval[outlength]='\0';
       return retval;
 }
 
