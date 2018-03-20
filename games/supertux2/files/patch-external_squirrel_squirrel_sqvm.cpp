The squirrel headers #define type , which plays havoc with
other headers that use type as a variable name or structure member.
Move other headers before the offending squirrel header.

In file included from /usr/include/c++/v1/math.h:310:
/usr/include/c++/v1/limits:232:90: error: member reference base type 'int' is not a structure or union
    _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR type infinity() _NOEXCEPT {return type(0);}
                                                                                         ^~~~~~~
/wrkdirs/usr/ports/games/supertux2/work/supertux-0.4.0/external/squirrel/squirrel/sqobject.h:131:25: note: expanded from macro 'type'
#define type(obj) ((obj)._type)


--- external/squirrel/squirrel/sqvm.cpp.orig	2018-03-20 18:48:11.028369000 +0000
+++ external/squirrel/squirrel/sqvm.cpp	2018-03-20 18:48:32.059836000 +0000
@@ -1,8 +1,8 @@
 /*
 	see copyright notice in squirrel.h
 */
-#include "sqpcheader.h"
 #include <math.h>
+#include "sqpcheader.h"
 #include <stdlib.h>
 #include "sqopcodes.h"
 #include "sqvm.h"
