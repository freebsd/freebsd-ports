Avoid adding #include <iostream> in lots of .cpp files, at the cost
of compilation time because iostream is no longer forward-declared.

--- src/Helper/Logger/Logger.h.orig	2017-10-06 07:14:44 UTC
+++ src/Helper/Logger/Logger.h
@@ -21,7 +21,7 @@
 #ifndef LOGGER_H
 #define LOGGER_H
 
-#include <iosfwd>
+#include <iostream>
 #include <typeinfo>
 #include <type_traits>
 #include <QList>
