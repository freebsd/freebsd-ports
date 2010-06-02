
$FreeBSD$

--- src/tools/hunspell.cxx.orig
+++ src/tools/hunspell.cxx
@@ -61,26 +61,22 @@
 #include "firstparser.hxx"
 
 #define LIBDIR \
-    "/usr/share/hunspell:" \
-    "/usr/share/myspell:" \
-    "/usr/share/myspell/dicts"
+    "%%PREFIX%%/share/hunspell:" \
+    "%%PREFIX%%/share/myspell:" \
+    "%%PREFIX%%/share/myspell/dicts"
 #define USEROOODIR \
     ".openoffice.org/3/user/wordbook:" \
     ".openoffice.org2/user/wordbook:" \
     ".openoffice.org2.0/user/wordbook"
 #define OOODIR \
-    "/opt/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/opt/openoffice.org2.4/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.4/share/dict/ooo:" \
-    "/opt/openoffice.org2.3/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.3/share/dict/ooo:" \
-    "/opt/openoffice.org2.2/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.2/share/dict/ooo:" \
-    "/opt/openoffice.org2.1/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.1/share/dict/ooo:" \
-    "/opt/openoffice.org2.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.0/share/dict/ooo"
+    "%%PREFIX%%/openoffice.org3/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-3.0.0/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4.2/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4.1/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.2/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.1/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org2.0/share/dict/ooo:"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
