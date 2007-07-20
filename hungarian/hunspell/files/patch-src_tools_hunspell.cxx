
$FreeBSD$

--- src/tools/hunspell.cxx.orig
+++ src/tools/hunspell.cxx
@@ -59,16 +59,12 @@
 #include "manparser.hxx"
 #include "firstparser.hxx"
 
-#define LIBDIR "/usr/share/hunspell:/usr/share/myspell"
+#define LIBDIR "%%PREFIX%%/share/hunspell:%%PREFIX%%/share/myspell"
 #define USEROOODIR ".openoffice.org2/user/wordbook"
-#define OOODIR "/opt/openoffice.org2.3/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.3/share/dict/ooo:" \
-    "/opt/openoffice.org2.2/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.2/share/dict/ooo:" \
-    "/opt/openoffice.org2.1/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.1/share/dict/ooo:" \
-    "/opt/openoffice.org2.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.0/share/dict/ooo"
+#define OOODIR "%%PREFIX%%/openoffice.org-2.3/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.2/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.1/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org2.0/share/dict/ooo"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
