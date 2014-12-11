--- libmemcached/assert.hpp.orig	2014-12-10 05:16:11 UTC
+++ libmemcached/assert.hpp
@@ -51,8 +51,10 @@
 # ifdef _WIN32
 #  include <malloc.h>
 # else
+#ifdef HAVE_ALLOCA_H
 #  include <alloca.h>
 # endif
+# endif
 
 #ifdef __cplusplus
 # include <cstdarg>
