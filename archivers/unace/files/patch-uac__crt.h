
$FreeBSD$

--- uac_crt.h.orig
+++ uac_crt.h
@@ -4,7 +4,7 @@
 
 #include "acestruc.h"
 
-CHAR *ace_fname(CHAR * s, thead * head, INT nopath);
+CHAR *ace_fname(CHAR * s, thead * head, INT nopath, unsigned int size);
 INT  create_dest_file(CHAR * file, INT a);
 
 #ifdef UNIX
