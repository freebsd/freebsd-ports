
$FreeBSD$

--- tools/build/buildexe.c.orig	Sat Nov  2 04:25:49 2002
+++ tools/build/buildexe.c	Fri Apr 25 10:23:19 2003
@@ -1170,7 +1170,9 @@
         } else if (strstr(p, "invalid offsetof from non-POD type")) {
             // Ignore this
             goto notgcc;
-        }
+        } else if (strstr(p, "from ")) {
+	    goto notgcc;
+	}
         p1 = strchr(p, ':');
         if (!p1) {
             // not of the form "filename:..."
@@ -1194,6 +1196,20 @@
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
