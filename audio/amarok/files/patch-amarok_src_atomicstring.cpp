
$FreeBSD$

--- amarok/src/atomicstring.cpp.orig
+++ amarok/src/atomicstring.cpp
@@ -17,13 +17,13 @@
   Boston, MA 02110-1301, USA.
 */
 
-#include <stdint.h>
+#include <inttypes.h>
 #include <qdeepcopy.h>
 #include <qstring.h>
 
 #include "atomicstring.h"
 
-#ifdef __GNUC__
+#if __GNUC__ >= 3
 
     // Golden ratio - arbitrary start value to avoid mapping all 0's to all 0's
     // or anything like that.
@@ -80,16 +80,6 @@
         bool operator()( const QString *a, const QString *b ) const
         {
             return *a == *b;
-        }
-    };
-
-#else
-
-    struct AtomicString::less
-    {
-        bool operator()( const QString *a, const QString *b ) const
-        {
-            return *a < *b;
         }
     };
 
