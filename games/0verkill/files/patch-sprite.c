--- sprite.c.orig	2001-12-15 20:51:53.000000000 +0300
+++ sprite.c	2013-11-17 13:00:40.184048213 +0400
@@ -2,6 +2,7 @@
 #include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #ifndef WIN32
 #include "config.h"
@@ -188,6 +189,14 @@
  
 	if (!(f=fopen(filename,"rb")))
 	{
+		chdir(DATA_PATH);
+	}
+	if (!(f=fopen(filename,"rb")))
+	{
+		chdir(DATA_PATH "/../");
+	}
+	if (!(f=fopen(filename,"rb")))
+	{
 		unsigned char msg[256];
 		snprintf(msg,256,"Error opening file \"%s\"!\n",filename);
 		ERROR(msg);
