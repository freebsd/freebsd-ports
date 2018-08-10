After https://reviews.llvm.org/rL301060 build fails:

In file included from sqvm.cpp:5:
In file included from /usr/include/c++/v1/math.h:310:
/usr/include/c++/v1/limits:148:85: error: expected expression
    _LIBCPP_INLINE_VISIBILITY static _LIBCPP_CONSTEXPR type min() _NOEXCEPT {return type();}
                                                                                    ^
../../../../src/include/scripting/squirrel/sqobject.h:99:24: note: expanded from macro 'type'
#define type(obj) ((obj)._type)
                       ^

--- src/sdk/scripting/squirrel/sqvm.cpp.orig	2013-08-18 05:51:11 UTC
+++ src/sdk/scripting/squirrel/sqvm.cpp
@@ -1,9 +1,9 @@
 /*
 	see copyright notice in squirrel.h
 */
-#include "sqpcheader.h"
 #include <math.h>
 #include <stdlib.h>
+#include "sqpcheader.h"
 #include "sqopcodes.h"
 #include "sqfuncproto.h"
 #include "sqvm.h"
