--- src/protocol/ArgParser.cxx.orig	2021-10-14 13:25:21 UTC
+++ src/protocol/ArgParser.cxx
@@ -24,6 +24,7 @@
 #include "util/NumberParser.hxx"
 
 #include <stdlib.h>
+#include <stdio.h>
 
 static inline ProtocolError
 MakeArgError(const char *msg, const char *value) noexcept
