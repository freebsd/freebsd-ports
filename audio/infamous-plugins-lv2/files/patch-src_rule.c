--- src/rule.c.orig	2017-08-06 09:17:53 UTC
+++ src/rule.c
@@ -43,7 +43,7 @@ void useage()
     return;
 }
 
-int main(int argc, int8_t **argv)
+int main(int argc, const char **argv)
 {
     uint8_t rule=0xD0;//0x7c;
     uint8_t t;
