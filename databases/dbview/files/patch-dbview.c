--- dbview.c.orig	Tue Oct 8 11:04:23 1996
+++ dbview.c Wed Apr 17 16:16:53 2002
@@ -34,19 +34,19 @@
 
 void help_short()
 {
-    printf ("%s %s - %s, (c) 1996 by Martin Schulze\n", progname, version, longname);
+    printf ("%s %s - %s, (c) 1996 by Martin Schulze, Patched Alexander Trapeznikov, 2001 \n", progname, version, longname);
     printf ("\n");
-    printf ("%s [-b [-t]] [-d delim] [-e] [-h] [-i] [-o] [-o] [-v] dbfile\n", progname);
+    printf ("%s [-b [-t]] [-d delim] [-e] [-h|-H] [-i] [-o] [-o] [-v] dbfile\n", progname);
 }
 
 void help_long()
 {
-    printf ("%s %s - %s, (c) 1996 by Martin Schulze\n", progname, version, longname);
+    printf ("%s %s - %s, (c) 1996 by Martin Schulze, Patched Alexander Trapeznikov, 2001 \n", progname, version, longname);
     printf ("\n");
     printf ("  --browse, -b           browse the database\n");
     printf ("  --delimiter, -d        set the delimiter for browse output\n");
     printf ("  --description, -e      display field description\n");
-    printf ("  --help, -h             display help\n");
+    printf ("  --help, -H, -h         display help\n");
     printf ("  --info, -i             display db information\n");
     printf ("  --omit, -o             omit db records\n");
     printf ("  --reserve, -r          reserve fieldnames from beeing translated\n");
@@ -54,7 +54,7 @@
     printf ("  --version, -v          display version\n");
 }
 
-void main (int argc, char **argv)
+int main (int argc, char **argv)
 {
     int opt_index;
     char c;
@@ -80,6 +80,8 @@
 	switch (c) {
 	case 'H':	/* --help */
 	    help_long (); exit (0);
+        case 'h':       /* --help */
+            help_long (); exit (0);
 	case 'b':
 	    flags |= DB_FL_BROWSE;
 	    break;
@@ -93,8 +95,6 @@
 	case 'e':
 	    flags |= DB_FL_DESCR;
 	    break;
-	case 'h':
-	    help_short (); exit (0);
 	case 'i':
 	    flags |= DB_FL_INFO;
 	    break;
