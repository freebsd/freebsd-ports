Fix the build on 8-i386. All other architectures and versions are fine.

/wrkdirs/usr/ports/devel/kdevelop-kde4/work/kdevelop-4.7.0/languages/cpp/parser/rpp/pp-engine.cpp: In member function 'rpp::Value rpp::pp::eval_multiplicative(rpp::Stream&)':
/wrkdirs/usr/ports/devel/kdevelop-kde4/work/kdevelop-4.7.0/languages/cpp/parser/rpp/pp-engine.cpp:588:103: error: 'LLONG_MIN' was not declared in this scope
       if (value.is_zero() || (!value.is_ulong() && !result.is_ulong() && value.l == -1 && result.l == LLONG_MIN)) {
                                                                                                       ^
/wrkdirs/usr/ports/devel/kdevelop-kde4/work/kdevelop-4.7.0/languages/cpp/parser/rpp/pp-engine.cpp:601:103: error: 'LLONG_MIN' was not declared in this scope
       if (value.is_zero() || (!value.is_ulong() && !result.is_ulong() && value.l == -1 && result.l == LLONG_MIN)) {
                                                                                                       ^
languages/cpp/parser/rpp/CMakeFiles/kdev4cpprpp.dir/build.make:172: recipe for target 'languages/cpp/parser/rpp/CMakeFiles/kdev4cpprpp.dir/pp-engine.cpp.o' failed
--- languages/cpp/parser/rpp/pp-engine.cpp
+++ languages/cpp/parser/rpp/pp-engine.cpp
@@ -22,6 +22,8 @@
 
 #include "pp-engine.h"
 
+#include <climits>
+
 #include <QFile>
 #include <QTextStream>
 
