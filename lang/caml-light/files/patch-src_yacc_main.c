--- src/yacc/main.c.orig	1995-06-07 15:34:32.000000000 +0200
+++ src/yacc/main.c	2011-11-12 10:09:52.000000000 +0100
@@ -1,4 +1,5 @@
 #include <signal.h>
+#include <stdlib.h> /* for mkstemp(), getenv() */
 #include "defs.h"
 
 char dflag;
@@ -31,6 +32,11 @@
 char *union_file_name;
 char *verbose_file_name;
 
+static int action_fd = -1;
+static int entry_fd = -1;
+static int text_fd = -1;
+static int union_fd = -1;
+
 FILE *action_file;	/*  a temp file, used to save actions associated    */
 			/*  with rules until the parser is written	    */
 FILE *entry_file;
@@ -72,7 +78,6 @@
 extern char *mktemp();
 extern char *getenv();
 
-
 done(k)
 int k;
 {
@@ -276,11 +281,20 @@
     union_file_name[len + 5] = 'u';
 
 #ifndef NO_UNIX
-    mktemp(action_file_name);
-    mktemp(entry_file_name);
-    mktemp(text_file_name);
-    mktemp(union_file_name);
+    action_fd = mkstemp(action_file_name);
+    entry_fd = mkstemp(entry_file_name);
+    text_fd = mkstemp(text_file_name);
+    union_fd = mkstemp(union_file_name);
 #endif
+    if (action_fd < 0)
+	open_error(action_file_name);
+    if (entry_fd < 0)
+	open_error(entry_file_name);
+    if (text_fd < 0)
+	open_error(text_file_name);
+    if (union_fd < 0)
+	open_error(union_file_name);
+
 
     len = strlen(file_prefix);
 
@@ -321,15 +335,15 @@
 	    open_error(input_file_name);
     }
 
-    action_file = fopen(action_file_name, "w");
+    action_file = fdopen(action_fd, "w");
     if (action_file == 0)
 	open_error(action_file_name);
 
-    entry_file = fopen(entry_file_name, "w");
+    entry_file = fdopen(entry_fd, "w");
     if (entry_file == 0)
 	open_error(entry_file_name);
 
-    text_file = fopen(text_file_name, "w");
+    text_file = fdopen(text_fd, "w");
     if (text_file == 0)
 	open_error(text_file_name);
 
@@ -345,7 +359,7 @@
 	defines_file = fopen(defines_file_name, "w");
 	if (defines_file == 0)
 	    open_error(defines_file_name);
-	union_file = fopen(union_file_name, "w");
+	union_file = fdopen(union_fd, "w");
 	if (union_file ==  0)
 	    open_error(union_file_name);
     }
