
$FreeBSD$

--- tools/build/buildexe.c.orig	Thu Jun 20 02:45:40 2002
+++ tools/build/buildexe.c	Fri Jul 26 22:17:07 2002
@@ -1152,7 +1152,9 @@
         } else if (strstr(p, "might be clobbered by `longjmp' or `vfork'")) {
             // Ignore this warning, too
             goto notgcc;
-        }
+        } else if (strstr(p, "from ")) {
+	    goto notgcc;
+	}
         p1 = strchr(p, ':');
         if (!p1) {
             // not of the form "filename:..."
@@ -1176,6 +1178,20 @@
         }
         *p1 = '\0'; // null-terminate the line number
         p1++;
+
+	// Check that there is a sub-line number appeared in gcc 3.x
+	if (isdigit(*p1)) {
+	    // Skip over the line number and following collon
+	    do {
+		p1++;
+	    } while (isdigit(*p1));
+	    if (*p1 != ':') {
+		// not of the form "filename:linenum:sublinenum:"
+		goto notgcc;
+	    }
+	    p1++;
+	}
+
         if (TestPrefix(&p1, " warning: ")) {
           // Found a warning
           Warning = TRUE;
@@ -2111,7 +2127,8 @@
         }
 #ifdef __GNUC__
   else
-    if ( TestPrefixPath( &p, "gcc " )) {
+    if ( TestPrefixPath( &p, "cc " )) {
+	 {static int i = 0; while (i);}
          ThreadState->FilterProc = GCCFilter;
          ThreadState->ChildFlags = 0;
          if ( strstr( p, "-Wall" ) != NULL || strstr( p, "-Werror" ) != NULL) {
