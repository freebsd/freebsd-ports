Obtained from:	https://github.com/xapian/xapian/commit/40f35d33ee31433b00e8241ba29f03ce8f98477a

--- net/resolver.h.orig	2017-04-24 02:19:20 UTC
+++ net/resolver.h
@@ -23,6 +23,7 @@
 
 #include <cstring>
 #include "safenetdb.h"
+#include "safesyssocket.h"
 #include "str.h"
 #include "xapian/error.h"
 
