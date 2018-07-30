./pac.h:36:30: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
#define PACTITLE "Pacman v. "VERSION" \xa9 1995,1999,2000 by Roar Thron\xe6s"
                             ^

--- pac.h.orig	2018-07-30 09:36:15 UTC
+++ pac.h
@@ -33,7 +33,7 @@ void writetext(); //just draw text
                   
 //change my name and you will be sued!!!!!!!!!!!!!!!!!!!!!!!!!!
 #ifndef VMS
-#define PACTITLE "Pacman v. "VERSION" \xa9 1995,1999,2000 by Roar Thron\xe6s"
+#define PACTITLE "Pacman v. " VERSION " \xa9 1995,1999,2000 by Roar Thron\xe6s"
 #else
 #define PACTITLE "Pacman v. 1_002 \xa9 1995,1999,2000 by Roar Thron\xe6s"
 #endif
