--- cgit.h.orig	2012-03-18 11:16:27.000000000 +0100
+++ cgit.h	2012-04-29 00:43:18.784960000 +0200
@@ -2,25 +2,25 @@
 #define CGIT_H
 
 
-#include <git-compat-util.h>
-#include <cache.h>
-#include <grep.h>
-#include <object.h>
-#include <tree.h>
-#include <commit.h>
-#include <tag.h>
-#include <diff.h>
-#include <diffcore.h>
-#include <refs.h>
-#include <revision.h>
-#include <log-tree.h>
-#include <archive.h>
-#include <string-list.h>
-#include <xdiff-interface.h>
-#include <xdiff/xdiff.h>
-#include <utf8.h>
-#include <notes.h>
-#include <graph.h>
+#include <git/git-compat-util.h>
+#include <git/cache.h>
+#include <git/grep.h>
+#include <git/object.h>
+#include <git/tree.h>
+#include <git/commit.h>
+#include <git/tag.h>
+#include <git/diff.h>
+#include <git/diffcore.h>
+#include <git/refs.h>
+#include <git/revision.h>
+#include <git/log-tree.h>
+#include <git/archive.h>
+#include <git/string-list.h>
+#include <git/xdiff-interface.h>
+#include <git/xdiff/xdiff.h>
+#include <git/utf8.h>
+#include <git/notes.h>
+#include <git/graph.h>
 
 
 /*
