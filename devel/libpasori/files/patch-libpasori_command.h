--- src/libpasori_command.h.orig	Mon Mar 20 09:12:58 2006
+++ src/libpasori_command.h	Fri Jan 19 00:38:48 2007
@@ -2,8 +2,8 @@
 #define __LIBPASORI_COMMAND_H
 
 int pasori_init(pasori*);
-int pasori_write(pasori*,uint8,uint8);
-int pasori_read(pasori*,uint8,uint8);
+int pasori_write(pasori*,uint8*,uint8);
+int pasori_read(pasori*,uint8*,uint8);
 
 felica* felica_polling(pasori*,uint16,uint8,uint8);
 int felica_read_without_encryption02(felica* f,int servicecode,int mode,uint8 addr,uint8* b);
