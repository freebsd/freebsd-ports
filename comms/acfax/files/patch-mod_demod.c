$FreeBSD$

--- mod_demod.c.orig	Sat Jun  8 00:38:29 2002
+++ mod_demod.c	Sat Jun  8 00:38:41 2002
@@ -29,6 +29,8 @@
 #include <unistd.h>
 #include "mod_demod.h"
 
+#define PI M_PI
+
 SHORT int firwide[] = {  6,   20,   7, -42, -74, -12, 159, 353, 440 };
 SHORT int firmiddle[] = {   0, -18, -38, -39,   0,  83, 191, 284, 320 };
 SHORT int firnarrow[] = {  -7, -18, -15,  11,  56, 116, 177, 223, 240 };
