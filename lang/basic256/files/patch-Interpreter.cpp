Drop 'using namespace std' to avoid errors when building in C++11 mode. This
can happen on FreeBSD 10+ and Qt 5.6+, where Qt may end up passing -std=gnu++11
and lead the call to bind(2) becoming a call to std::bind().

Interpreter.cpp:4282:105: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned long>' and 'int')

Submitted upstream: https://sourceforge.net/p/kidbasic/patches/30/
--- Interpreter.cpp.orig	2016-09-03 10:00:06 UTC
+++ Interpreter.cpp
@@ -66,7 +66,6 @@ InpOut32OutType Out32 = NULL;
 
 #include <QtWidgets/QMessageBox>
 
-using namespace std;
 
 #include "LEX/basicParse.tab.h"
 #include "WordCodes.h"
