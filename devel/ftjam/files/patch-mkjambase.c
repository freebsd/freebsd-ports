--- mkjambase.c.orig	2014-08-07 15:44:34.000000000 +0200
+++ mkjambase.c	2014-08-07 15:44:46.000000000 +0200
@@ -24,7 +24,7 @@
 # include <stdio.h>
 # include <string.h>
 
-main( int argc, char **argv, char **envp )
+int main( int argc, char **argv, char **envp )
 {
 	char buf[ 1024 ];
 	FILE *fin;
