--- src/Base64Encoder.cpp.orig	2018-02-21 15:13:36 UTC
+++ src/Base64Encoder.cpp
@@ -167,7 +167,7 @@ char * Base64Encoder::encode(const char *data, int dat
                   linelength=0;
             }
       };
-      retval[outlength]=(char) NULL;
+      retval[outlength]='\0';
       return retval;
 }
 
