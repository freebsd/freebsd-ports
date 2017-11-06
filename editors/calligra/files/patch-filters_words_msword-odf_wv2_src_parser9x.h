To use 'uint' we need to include '<sys/types.h>'.

--- filters/words/msword-odf/wv2/src/parser9x.h.orig	2016-12-20 09:48:40 UTC
+++ filters/words/msword-odf/wv2/src/parser9x.h
@@ -27,6 +27,8 @@
 #include <list>
 #include <stack>
 
+#include <sys/types.h>
+
 class QString;
 
 namespace wvWare
