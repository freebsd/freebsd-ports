--- src/af/util/xp/ut_string_class.cpp.orig	Mon Aug 25 03:34:03 2003
+++ src/af/util/xp/ut_string_class.cpp	Mon Aug 25 03:42:00 2003
@@ -28,6 +28,7 @@
 #include <locale.h>
 #include <ctype.h>
 #include <stdarg.h>
+#include <glib.h>
 
 #include "ut_string.h"
 #include "ut_string_class.h"
@@ -340,13 +341,13 @@
   return len;
 }
 
+#define VA_COPY G_VA_COPY
+
 #if !defined (VA_COPY)
 #  if defined (__GNUC__) && defined (__PPC__) && (defined (_CALL_SYSV) || defined (_WIN32) || defined(WIN32)) || defined(__s390__) || defined(__x86_64__)
 #  define VA_COPY(ap1, ap2)	  (*(ap1) = *(ap2))
 #  elif defined (VA_COPY_AS_ARRAY)
 #  define VA_COPY(ap1, ap2)	  memmove ((ap1), (ap2), sizeof (va_list))
-#  elif defined (__GNUC__)
-#  define VA_COPY(ap1,ap2)     __va_copy((ap1),(ap2))
 #  else /* va_list is a pointer */
 #  define VA_COPY(ap1, ap2)	  ((ap1) = (ap2))
 #  endif /* va_list is a pointer */
