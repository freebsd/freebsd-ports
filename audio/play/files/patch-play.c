--- play.c.orig	1997-03-25 15:25:12 UTC
+++ play.c
@@ -4,6 +4,7 @@ static char rcsid[] = "$Id: play.c,v 1.7
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include <err.h>
 #include <signal.h>
