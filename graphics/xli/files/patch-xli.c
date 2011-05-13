--- xli.c.orig	2006-11-10 23:52:14.000000000 -0600
+++ xli.c	2011-04-08 04:57:58.469540144 -0500
@@ -364,6 +364,7 @@ int main(int argc, char *argv[])
 				idisp = itmp;
 			}
 			freeImage(inew);
+			inew = idisp;
 		}
 
 		/*
