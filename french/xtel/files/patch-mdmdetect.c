--- mdmdetect.c.orig	Sat Jan 26 22:38:32 2002
+++ mdmdetect.c	Sat Jan 26 22:44:35 2002
@@ -37,7 +37,16 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#ifdef NO_TERMIO
+#include <sgtty.h>
+#else
+#ifdef USE_TERMIOS
+#include <sys/ioctl.h>
+#include <termios.h>
+#else
 #include <termio.h>
+#endif /* USE_TERMIOS */
+#endif
 #ifdef SVR4
 #include <sys/mkdev.h>
 #endif /* SVR4 */
@@ -71,6 +80,18 @@
     exit (1);
 }
 
+char *CtrlArg (arg)
+char *arg;
+{
+  static char ret[240];
+
+  if(strlcpy(ret, arg, 240) >= 240) {
+	fprintf(stderr, "Argument trop long: %s\n", arg);
+	exit (1);
+  }
+  return (ret);
+}
+
 /* Sortie */
 static void the_end (r)
 int r;
@@ -228,23 +249,24 @@
 
   progname = xtel_basename(av[0]);
 
-  if (ac < 2)
+  if (ac < 2 || ac > 7)
     Usage (progname);
 
   /* Lecture de la ligne de commande */
   while (--ac) {
-    if ((cp = *++av) == NULL)
+    if ((cp = CtrlArg(*++av)) == NULL) {
       break;
+    }
     if (*cp == '-' && *++cp) {
       switch(*cp) {
       case 'b' :
-	builder = *++av; break;
+	builder = CtrlArg(*++av); break;
 
       case 'd' :
 	++debug; break;
 
       case 'l' :
-	modem_list = *++av; break;
+	modem_list = CtrlArg(*++av); break;
 
       case 'q' :
 	query = 1; break;
