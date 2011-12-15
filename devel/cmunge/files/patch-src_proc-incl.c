--- ./src/proc-incl.c.orig	1993-12-11 19:01:52.000000000 +0100
+++ ./src/proc-incl.c	2011-12-15 18:06:38.000000000 +0100
@@ -5,6 +5,8 @@
 /*----------------------------------------------------------------------*/
 /*{{{  global decls*/
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>		/* for 'stat ()' */
 #include <sys/stat.h>		/*  "     "    " */
 
@@ -247,7 +249,7 @@
 	int    processed,  val;
 
 	if ( !(dict_file = fopen (incl_dict_filename, "r")) )
-		return;
+		return 0;
 
 	next_val = 0;
 	while (fgets (buf, BUFLEN, dict_file) ) {
@@ -297,7 +299,7 @@
 	}
 
 	fclose (dict_file);
-	return;
+	return 0;
 }
 /*}}}*/
 /*{{{  write_new_dict () -- OK*/
@@ -362,7 +364,7 @@
 			while ((c = getchar ()) != delim) {
 				switch (c) {
 				case  EOF :
-					return;
+					return 0;
 			
 				case  '\\' :
 					/*---------------------------------------*/
@@ -370,7 +372,7 @@
 					/*---------------------------------------*/
 					putchar (c);
 					if ((c = getchar ()) == EOF)
-						return;
+						return 0;
 					putchar (c);
 					break;
 			
@@ -406,11 +408,11 @@
 				do {
 					switch (getchar ()) {
 					case  EOF :
-						return;
+						return 0;
 					case  '*' :
 						switch (c = getchar ()) {
 						case  EOF :
-							return;
+							return 0;
 						case  '/' :
 							in_comment = FALSE;
 							break;
