--- program.cc.orig	Tue Nov 19 12:38:52 2002
+++ program.cc	Tue Nov 19 12:39:56 2002
@@ -28,7 +28,7 @@
 
 */
 
-#include <iostream.h>
+#include <iostream>
 
 #include <unistd.h>
 #include <string.h>
@@ -258,7 +258,7 @@
 original licensor to copy, distribute or modify the Program subject to\n\
 these terms and conditions.  You may not impose any further\n\
 restrictions on the recipients' exercise of the rights granted herein.\n\
-You are not responsible for enforcing compliance by third parties to\n\
+You are not responsible for enforstd::cing compliance by third parties to\n\
 this License.\n\
 \n\
   7. If, as a consequence of a court judgment or allegation of patent\n\
@@ -356,7 +356,7 @@
       || 0 > ioctl (1, TIOCGWINSZ, &w)
       || w.ws_row < 2
       || w.ws_col < 76) {
-    cout << t;
+    std::cout << t;
     return;
   }
 
@@ -368,17 +368,17 @@
       char *tmps = new char [end-start+1];
       memcpy (tmps, start, end-start);
       tmps [end-start] = '\0';
-      cout << tmps;
+      std::cout << tmps;
       delete [] tmps;
       lines = 0;
       start = end;
-      cout << "Press enter to continue" << flush;
-      while (cin.get(c) && '\n' != c)
+      std::cout << "Press enter to continue" << std::flush;
+      while (std::cin.get(c) && '\n' != c)
 	;
     }
   }
   if (*start)
-    cout << start; // Print the last page.
+    std::cout << start; // Print the last page.
 }
 
 void program::warranty ()
@@ -394,7 +394,7 @@
 static void wrapif (int& column, int cols, int wid)
 {
   if (cols < (column += wid)) {
-    cerr << endl;
+    std::cerr << std::endl;
     column = wid;
   }
 }
@@ -413,7 +413,7 @@
       || w.ws_col < 40)
     w.ws_col = 80;
 
-  cerr << "Usage: " << name;
+  std::cerr << "Usage: " << name;
   column = 7 + strlen (name);
   memset (charops, 0, sizeof (charops));
   for (op = long_opts; op->name; op++) {
@@ -422,23 +422,23 @@
     switch (op->has_arg) {
     case required_argument:
       wrapif (column, w.ws_col, 5 + strlen (op->name) + 6);
-      cerr << " [ --" << op->name << "=arg ]";
+      std::cerr << " [ --" << op->name << "=arg ]";
       if (!op->flag) {
 	wrapif (column, w.ws_col, 11);
-	cerr << " [ -" << (char)op->val << " arg ]";
+	std::cerr << " [ -" << (char)op->val << " arg ]";
       }
       break;
     case optional_argument:
       wrapif (column, w.ws_col, 5 + strlen (op->name) + 9);
-      cerr << " [ --" << op->name << "[=arg ] ]";
+      std::cerr << " [ --" << op->name << "[=arg ] ]";
       if (!op->flag) {
 	wrapif (column, w.ws_col, 15);
-	cerr << " [ -" << (char)op->val << " [ arg ] ]";
+	std::cerr << " [ -" << (char)op->val << " [ arg ] ]";
       }
       break;
     default:
       wrapif (column, w.ws_col, 5 + strlen (op->name) + 2);
-      cerr << " [ --" << op->name << " ]";
+      std::cerr << " [ --" << op->name << " ]";
       if (!op->flag)
 	charops [strlen (charops)] = op->val;
     }
@@ -447,16 +447,16 @@
     if (' ' != *tmp_set && ':' != *tmp_set) {
       if (':' == tmp_set [1]) {
 	wrapif (column, w.ws_col, 12);
-	cerr << " [ -" << *tmp_set++ << " arg ]";
+	std::cerr << " [ -" << *tmp_set++ << " arg ]";
       } else
 	charops [strlen (charops)] = *tmp_set;
     }
   }
   if (charops[0]) {
     wrapif (column, w.ws_col, 4 + strlen (charops) + 2);
-    cerr << " [ -" << charops << " ]";
+    std::cerr << " [ -" << charops << " ]";
   }
-  cerr << endl;
+  std::cerr << std::endl;
   exit (EX_USAGE);
 }
 
