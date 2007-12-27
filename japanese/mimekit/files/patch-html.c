--- ../rary/html.c.orig	2007-11-11 18:21:43.000000000 +0900
+++ ../rary/html.c	2007-11-11 18:25:11.000000000 +0900
@@ -26,6 +26,8 @@
 	941002	extracted from http.c
 	990331	extracted attrWithURL() and made it custmizable
 //////////////////////////////////////////////////////////////////////#*/
+#include <stdio.h>
+#include <string.h>
 #include "ystring.h"
 /*
 #define isAlpha(ch)	(isalpha(ch) || ch == '-')
@@ -38,6 +40,10 @@
 int HTMLCONV_DEBUG = 0;
 int URL_SEARCH;
 
+static addTAGelem(char *name);
+static addTAGattr(char *attr);
+static count_convs(int convtype);
+
 static hconv1(conv)
 	char *conv;
 {	int onoff;
